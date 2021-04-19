#include <unistd.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <sys/wait.h>
#include <iomanip>
#include <climits>
#include "Commands.h"

using namespace std;
using std::vector;
using std::string;

#if 0
#define FUNC_ENTRY() \
  cout << __PRETTY_FUNCTION__ << " --> " << endl;

#define FUNC_EXIT() \
  cout << __PRETTY_FUNCTION__ << " <-- " << endl;
#else
#define FUNC_ENTRY()
#define FUNC_EXIT()
#endif

const string GetCurrentWorkingDirectory();
string _ltrim(const string &s);
string _rtrim(const string &s);
string _trim(const string &s);

int _parseCommandLine(const char *cmd_line, char **args);
bool _isBackgroundComamnd(const char *cmd_line);
void _removeBackgroundSign(char *cmd_line);
bool is_number(const std::string& s);

void log_error(const char *text,const bool &use_perror = false );

// String manipulation
string _ltrim(const string &s)
{
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == string::npos) ? "" : s.substr(start);
}

string _rtrim(const string &s)
{
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string _trim(const string &s)
{
  return _rtrim(_ltrim(s));
}


int _parseCommandLine(const char *cmd_line, char **args)
{
  FUNC_ENTRY()
  int i = 0;

  std::istringstream iss(_trim(string(cmd_line)).c_str());
  for (string s; iss >> s;)
  {
    args[i] = (char *)malloc(s.length() + 1);
    memset(args[i], 0, s.length() + 1); // Make 's.length() + 1' bytes of zero
    strcpy(args[i], s.c_str());         // Copy the arguement
    args[++i] = NULL;
  }
  return i;

  FUNC_EXIT()
}
void log_error(const char *text,const bool &use_perror )
{
  string text_str(text);
  string message = "smash error: " + text_str;
  perror(message.c_str());
}
bool _isBackgroundComamnd(const char *cmd_line)
{
  const string str(cmd_line);
  return str[str.find_last_not_of(WHITESPACE)] == '&';
}

void _removeBackgroundSign(char *cmd_line)
{
  const string str(cmd_line);
  // find last character other than spaces
  unsigned int idx = str.find_last_not_of(WHITESPACE);
  // if all characters are spaces then return
  if (idx == string::npos)
  {
    return;
  }
  // if the command line does not end with & then return
  if (cmd_line[idx] != '&')
  {
    return;
  }
  // replace the & (background sign) with space and then remove all tailing spaces.
  cmd_line[idx] = ' ';
  // truncate the command line string up to the last non-space character
  cmd_line[str.find_last_not_of(WHITESPACE, idx) + 1] = 0;
}

bool is_unsigned_number(const char* str)
{
  char it = *str-1;
  while (++it)
  {
     if (!std::isdigit(it))
     {
        return false;
     }
  }
  return true;
  
}

SmallShell::SmallShell()
{
  this->prompt_name = DEFAULT_PROMPT;
  this->last_wd = nullptr;
  this->jobs_list = new JobsList();
}

SmallShell::~SmallShell()
{
  // TODO: add your implementation
  free(last_wd);
  delete this->jobs_list;
}
string SmallShell::getPromptName()
{
  return prompt_name;
}
void SmallShell::changePrompt(const char *cmd_line)
{
  char **args = (char **)malloc(sizeof(char *) * COMMAND_MAX_ARGS);
  int argc = _parseCommandLine(cmd_line, args);
  if (argc < 1)
  {
    log_error("chprompt: too few arguments"); // CHECK with staff!
  }
  else if (argc == 1)
  {
    prompt_name = DEFAULT_PROMPT;
  }
  else
  {
    prompt_name = args[1];
  }
}
Command *SmallShell::CreateCommand(const char *cmd_line)
{
  // For example:

  string cmd_s = _trim(string(cmd_line));
  string firstWord = cmd_s.substr(0, cmd_s.find_first_of(" \n"));

  if (firstWord.compare(PRINT_WORKING_DIRECTORY_STR) == 0)
  {
    return new GetCurrDirCommand(cmd_line);
  }
  else if (firstWord.compare(SHOW_PID_COMMAND_STR) == 0)
  {
    return new ShowPidCommand(cmd_line);
  }
  else if (firstWord.compare(CHANGE_DIRECTORY_COMMAND_STR) == 0)
  {
    return new ChangeDirCommand(cmd_line, &last_wd);
  }
  else if (firstWord.compare(CHANGE_PROMPT_COMMAND_STR) == 0)
  {
    changePrompt(cmd_line);
  }
  else if (firstWord.compare(JOBS_COMMAND_STR) == 0)
  {
    return new JobsCommand(cmd_line, jobs_list);
  }
  else
  {
    //return new ExternalCommand(cmd_line);
  }

  return nullptr;
}

void SmallShell::executeCommand(const char *cmd_line)
{
  // TODO: Add your implementation here
  // for example:
  jobs_list->removeFinishedJobs();
  Command *cmd = CreateCommand(cmd_line);
  if (cmd)
  {
    BuiltInCommand *temp_cmd = dynamic_cast<BuiltInCommand *>(cmd);
    if (temp_cmd)
    {
      // Command is NOT built in
      cmd->execute();
    }
    else
    {
      // We should fork here
    }
  }

  // Please note that you must fork smash process for some commands (e.g., external commands....)
}


BuiltInCommand::BuiltInCommand(const char *cmd_line) : Command(cmd_line)
{
  this->args = (char **)malloc(sizeof(char *) * COMMAND_MAX_ARGS);
  this->argc = _parseCommandLine(cmd_line, this->args);
}

BuiltInCommand::~BuiltInCommand()
{
  for (int i = 0; i < argc; i++)
  {
    free(args[i]);
  }
  free(args);
}

void ShowPidCommand::execute()
{
  cout << "smash pid is " << getpid() << endl;
}
void JobsCommand::execute()
{
  jobs->removeFinishedJobs();
  jobs->printJobsList();
}
void ChangeDirCommand::execute()
{
  if (argc < 2)
  {
    log_error("cd: too few arguments"); // CHECK with staff!
    return;
  }
  else if (this->argc > 2)
  {
    log_error("cd: too many arguments");
    return;
  }
  const char *first_arg = args[1];
  const char *path = (strlen(first_arg) == 1 && *(first_arg) == CHANGE_DIRECTORY_LAST_ARG) ? *plastPwd : first_arg;
  string temp =  GetCurrentWorkingDirectory();
  const char *current_dir =temp.c_str();
  if (path == nullptr)
  {
    log_error("cd: OLDPWD not set");
  }
  else if (chdir(path))
  { // Error
    log_error("chdir failed",true);
  }
  else
  { // cd successfull
    if (!*plastPwd)
    {
      (*plastPwd) = (char *)malloc(COMMAND_ARGS_MAX_LENGTH + 1);
    }
    strcpy(*plastPwd, current_dir);
  }
}

void GetCurrDirCommand::execute()
{
  if (argc < 1)
  {
    log_error("cd: too few arguments"); // CHECK with staff!
    return;
  }

 
  cout << GetCurrentWorkingDirectory() << endl;
  return;
}

const string GetCurrentWorkingDirectory()
{
  char buff[PATH_MAX];
    
    if (!getcwd(buff, PATH_MAX))
    {
      log_error("pwd: getcwd failed",true); // CHECK with staff!
      return ""; // Won't reach this if cd was successful
    }
     
    return string(buff);
}
std::ostream &operator<<(std::ostream &os, const JobsList::JobEntry &job_entry)
{
  string suffix = job_entry.job_stopped ? " (stopped)" : "";
  os << '[' << job_entry.job_id << "] " << *(job_entry.cmd) << " : " << job_entry.pid << ' '
     << difftime(time(NULL), job_entry.start_time) << " secs" << suffix;
  return os;
}
void JobsList::printJobsList() const
{
  for (auto job_entry = jobs_list.rbegin(); job_entry != jobs_list.rend(); ++job_entry)
  {
    cout << *job_entry << endl;
  }
}
const unsigned int JobsList::removeFinishedJobs()
{
  // Due to complexity concers, move all vector to new vector
  unsigned int max_job_id=JOB_ID_INITIAL_VALUE;
  vector<JobEntry> new_job_list;
  for (auto &job_entry : this->jobs_list)
  {
   // if(kill(job_entry.GetPid(), 0)) // process didn't finish
    if(1)
    {
        new_job_list.push_back(job_entry);
    }
    else if(const unsigned int new_id = job_entry.job_id > max_job_id)
    {
      max_job_id = new_id;
    }
    
  }
  jobs_list=new_job_list;
  return max_job_id;
}
void JobsList::removeJobById(const unsigned int &jobId)
{
  unsigned int count=0;
  for (auto &job_entry : jobs_list)
  {
    if(job_entry.job_id == jobId)
    {
      jobs_list.erase(jobs_list.begin()+count);
      return;
    }
    count++;
  }
}
JobsList::JobEntry *JobsList::getLastStoppedJob(int *jobId)
{
  for (vector<JobsList::JobEntry>::reverse_iterator job_entry = jobs_list.rbegin(); job_entry != jobs_list.rend(); ++job_entry)
  { // Consider creating array for pointer in order to support complexity of O(1)...
    if (job_entry->job_stopped)
    {
      *jobId = job_entry->job_id;
      return &(*job_entry); // dereference iterator and pass as pointer
    }

    
  }
  return nullptr;
}

 std::ostream & operator<<(std::ostream & os, const Command & cmd)
 {
   os << cmd.cmd_line;
   return os;
 }
 void ForegroundCommand::execute()
 {
   if(this->jobs->getLastJob(nullptr)) // No jobs
   {
     log_error("fg: jobs list is empty");
   }
   else if(argc > 2 || !is_unsigned_number(args[1]) )
   {
     log_error("fg: invalid arguments");
   }
   else 
   {
     const unsigned int job_id= std::stoi(args[1]);
     if(JobsList::JobEntry* job_p = this->jobs->getJobById(job_id))
     {
       log_error("fg: job-id <job-id> does not exist");
     }
     else
     {
       pid_t job_pid =job_p->pid;
        if(kill(job_pid,SIGCONT)==-1)
        {
            log_error("fg: kill failed");
            return;
        }
        
        // SIGCONT succeeded
        cout << job_p->cmd << " : " << job_pid;
        this->jobs->removeJobById(job_id);
        int *status = nullptr;
        if (waitpid(job_pid,status,0)==-1)
        {
             log_error("fg: waitpid failed");
            return;
        }
     }

   }
 }