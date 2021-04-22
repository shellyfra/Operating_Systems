#include <unistd.h>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <sys/wait.h>
#include <iomanip>
#include <climits>
#include <ctype.h>
#include <fcntl.h>
#include<algorithm>
#include "Commands.h"

using namespace std;
using std::string;
using std::vector;


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
static bool _isNumber(const std::string &s);
static void _logError(std::string text);

// String manipulation
string _ltrim(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? EMPTY_STRING : s.substr(start);
}

string _rtrim(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? EMPTY_STRING : s.substr(0, end + 1);
}

string _trim(const string &s)
{
    return _rtrim(_ltrim(s));
}

static void _logError(std::string text)
{
    string message = ERROR_PREFIX + text;

        cerr << message << endl;
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

bool _isBackgroundComamnd(const char *cmd_line)
{
    const string str(cmd_line);
    return str[str.find_last_not_of(WHITESPACE)] == BACKGROUND_IDENTIFIER;
}

void _removeBackgroundSign(char *cmd_line)
{
    const string str(cmd_line);
    if (str.empty())
        return;
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

bool _isNumber(char *str)
{
    char *it = str;
    while (char current = (*it++))
    {
        if (!std::isdigit(current) && current != MINUS_SIGN)
        {
            return false;
        }
    }
    return true;
}
Command::Command(const char *usr_cmd_line) : cmd_line(new char[COMMAND_MAX_LENGTH])
                                                , cmd_line_wo_ampersand(new char[COMMAND_MAX_LENGTH])
{
    strcpy(this->cmd_line, usr_cmd_line);
    strcpy(this->cmd_line_wo_ampersand, usr_cmd_line);
    _removeBackgroundSign(cmd_line_wo_ampersand);
};
Command::~Command()
{
    free(cmd_line);
    free(cmd_line_wo_ampersand);
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


Command *SmallShell::CreateCommand(const char *cmd_line)
{
    // For example:

    string cmd_s = _trim(string(cmd_line));
    string firstWord = cmd_s.substr(0, cmd_s.find_first_of(" \n"));

    if (cmd_s.find('>') != std::string::npos){
        return new RedirectionCommand(cmd_line, this);
    }
    else if (cmd_s.find('|') != std::string::npos) // Has pipe character
    { // Includes also |&
        return new PipeCommand(cmd_line);
    }
    else if (firstWord.compare(PRINT_WORKING_DIRECTORY_STR) == 0)
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
        return new ChangePromptCommand(cmd_line, &this->prompt_name);
    }
    else if (firstWord.compare(JOBS_COMMAND_STR) == 0)
    {
        return new JobsCommand(cmd_line, jobs_list);
    }
    else if (firstWord.compare(KILL_COMMAND_STR) == 0)
    {
        return new KillCommand(cmd_line, jobs_list);
    }
    else if (firstWord.compare(FOREGROUND_COMMAND_STR) == 0)
    {
        return new ForegroundCommand(cmd_line, jobs_list);
    }
    else if (firstWord.compare(QUIT_COMMAND_STR) == 0)
    {
        return new QuitCommand(cmd_line, jobs_list, ShouldRun());
    }
    else if (firstWord.compare(BG_COMMAND_STR) == 0)
    {
        return new BackgroundCommand(cmd_line, jobs_list);
    }
    else if (firstWord.compare(CAT_COMMAND_STR) == 0) {
        return new CatCommand(cmd_line);
    }

    else
    {
        return new ExternalCommand(cmd_line, jobs_list);
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
        cmd->execute();
    }

    // Please note that you must fork smash process for some commands (e.g., external commands....)
}

BuiltInCommand::BuiltInCommand(const char *cmd_line) : Command(cmd_line)
{
    this->args = (char **)malloc(sizeof(char *) * COMMAND_MAX_ARGS);
    this->argc = _parseCommandLine(cmd_line_wo_ampersand, this->args);
}
ExternalCommand::ExternalCommand(const char *cmd_line, JobsList *jobs) : Command(cmd_line), jobs(jobs)
{
    this->is_background = (_isBackgroundComamnd(cmd_line));
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
    //jobs->removeFinishedJobs();
    jobs->printJobsList();
}
void ChangeDirCommand::execute()
{
    if (argc < 2)
    {
        _logError("cd: too few arguments"); // CHECK with staff!
        return;
    }
    else if (this->argc > 2)
    {
        _logError("cd: too many arguments");
        return;
    }
    const char *first_arg = args[1];
    const char *path = (strlen(first_arg) == 1 && *(first_arg) == CHANGE_DIRECTORY_LAST_ARG) ? *plastPwd : first_arg;
    string temp = GetCurrentWorkingDirectory();
    const char *current_dir = temp.c_str();
    if (path == nullptr)
    {
        _logError("cd: OLDPWD not set");
        return;
    }
    DO_SYS(chdir(path));    
     // cd successfull
        if (!*plastPwd)
        {
            (*plastPwd) = (char *)malloc(COMMAND_ARGS_MAX_LENGTH + 1);
        }
        strcpy(*plastPwd, current_dir);
    
}

void GetCurrDirCommand::execute()
{
    if (argc < 1)
    {
        _logError("cd: too few arguments"); // CHECK with staff!
        return;
    }
    cout << GetCurrentWorkingDirectory() << endl;
}

const string GetCurrentWorkingDirectory()
{
    char buff[PATH_MAX];

    if (!getcwd(buff, PATH_MAX))
    {
        _logError("pwd: getcwd failed"); // CHECK with staff!
        return "";                       // Won't reach this if cd was successful
    }

    return string(buff);
}
std::ostream &operator<<(std::ostream &os, const JobsList::JobEntry &job_entry)
{
    string suffix = job_entry.job_stopped ? " (stopped)" : EMPTY_STRING;
    os << '[' << job_entry.job_id << "] " << *(job_entry.cmd) << " : " << job_entry.pid << ' '
       << difftime(time(NULL), job_entry.start_time) << " secs" << suffix;
    return os;
}
void JobsList::printJobsList() const
{
    for (auto job_entry = jobs_list.rbegin(); job_entry != jobs_list.rend(); ++job_entry)
    {        
        cout << (**job_entry) << endl;
    }
}
const unsigned int JobsList::removeFinishedJobs()
{
    // Due to complexity concers, move all vector to new vector
    unsigned int max_job_id = JOB_ID_INITIAL_VALUE;
    vector<JobEntry*> new_job_list;
    for (auto &job_entry : this->jobs_list)
    {
       
        int status;
        pid_t result = waitpid(job_entry->pid, &status, WNOHANG);
        if (result == 0)
        {
            // Child still alive
            new_job_list.push_back(job_entry);
            unsigned int new_id = job_entry->job_id;
            if (new_id > max_job_id)
            {
                max_job_id = new_id;
            }
        }
        else if (result == -1)
        {
            // Error
        } else {
           // child finished
        }
    }
    jobs_list = new_job_list;
    return max_job_id;
}
void JobsList::removeJobById(const unsigned int &jobId)
{
    unsigned int count = 0;
    for (auto &job_entry : jobs_list)
    {
        if (job_entry->job_id == jobId)
        {

            jobs_list.erase(jobs_list.begin() + count);
            return;
        }
        count++;
    }
}
JobsList::JobEntry* JobsList::getLastStoppedJob()
{
    for (auto job_entry = jobs_list.rbegin(); job_entry != jobs_list.rend(); ++job_entry)
    { // Consider creating array for pointer in order to support complexity of O(1)...
        if ((*job_entry)->job_stopped)
        {
            return *job_entry; // dereference iterator and pass as pointer
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &os, const Command &cmd)
{
    os << cmd.cmd_line;
    return os;
}

void ForegroundCommand::execute()
{
    if (! this->jobs->getLastJob()) // No jobs
    {
        _logError("fg: jobs list is empty");
    }
    else if (argc > 2 || !_isNumber(args[1]))
    {
        _logError("fg: invalid arguments");
    }
    else
    {
        const int job_id = std::stoi(args[1]);
        JobsList::JobEntry* job_entry = this->jobs->getJobById(job_id);
        if (job_id < 0 || !job_entry)
        {
            string error_msg = "fg: job-id " + std::to_string(job_id) + " does not exist";
            _logError(error_msg);
        }
        else
        {
            pid_t job_pid = job_entry->pid;
            DO_SYS(kill(job_pid, SIGCONT));

            // SIGCONT succeeded
            cout << job_entry->cmd << " : " << (*job_entry);
            this->jobs->removeJobById(job_id);
            int *status = nullptr;

            DO_SYS(waitpid(job_pid, status, 0));
        }
    }
}

void JobsList::addJob(Command *cmd, pid_t child_pid, const bool &isStopped)
{
    unsigned int new_job_id = removeFinishedJobs() + 1;
    JobEntry* new_job = new JobEntry(cmd, new_job_id, child_pid, isStopped);
    this->jobs_list.push_back(new_job);
}

void JobsList::killAllJobs()
{
    unsigned int count = 0;
    cout << "smash: sending SIGKILL signal to " << jobs_list.size() << " jobs:" << endl;
    for (auto &job_entry : jobs_list)
    {
        cout << job_entry->pid << ": " << (*job_entry->cmd) << endl;
        if (kill(job_entry->pid, SIGKILL) != 0)
        {
            _logError("killAllJobs: kill job failed"); // CHECK with staff!
            continue;                                  // not sure what to do here
        }
        DO_SYS(wait(NULL));
        //jobs_list.e   .erase(jobs_list.begin());
        count++;
    }
    jobs_list.clear();
}

JobsList::JobEntry* JobsList::getJobById(const unsigned int &jobId) const
{
    for (auto &job_entry : jobs_list)
    {
        if (job_entry->job_id == jobId)
        {
            return job_entry;
        }
    }
    return nullptr;
}

JobsList::JobEntry * JobsList::getLastJob() const
{
   // if (!jobs_list.empty())
  //  {
        /*
        unsigned int max_job_id = 0;
        JobsList::JobEntry* return_job;
        for (auto &job_entry : jobs_list)
        {
            if (job_entry->job_id > max_job_id)
            {
                return_job = job_entry;
            }
        }
        return return_job;
        */
   //    return jobs_list.back();
   // }
    return jobs_list.empty() ? nullptr : jobs_list.back();
}
static bool _isNumber(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}
void ChangePromptCommand::execute()
{
    // args[1] always exist
        *prompt_name_p = argc == 1 ? DEFAULT_PROMPT :args[1];
    
}
void KillCommand::execute()
{
    if (this->argc != 3)
    {
        _logError("kill: invalid arguments");
        return;
    }
    std::string first_arg = std::string(args[1]);
    char first_char = first_arg.at(0);
    first_arg.erase(first_arg.begin());
    std::string req_job_id_str = std::string(args[2]);
   // const unsigned int req_job_id = *args[2] - '0'; // won't work if ID is two digits..
    const unsigned int req_job_id = stoi(args[2]);
    //parse args
    if (first_char != '-' || !_isNumber(first_arg) || !_isNumber(req_job_id_str))
    {
        _logError("kill: invalid arguments");
        return;
    }
    JobsList::JobEntry* entry = jobs->getJobById(req_job_id);
    if (!entry)
    {
        std::string message = "kill: job-id " + req_job_id_str + " does not exist";
        _logError(message);
        return;
    }
    DO_SYS(kill(entry->pid, int(first_arg.at(0))));
    cout << "signal number " << first_arg << " was sent to pid " << entry->pid <<endl;
}
void QuitCommand::execute()
{
    if (strcmp(args[1], "kill") == 0)
    {
        jobs->killAllJobs();
    }
    should_run = false;
    while (waitpid(-1, NULL, WNOHANG) != -1){ // check if there are still live childs
        cout << "wait +1"<< endl;
    }
}

void BackgroundCommand::execute()
{

    if (this->argc > 2 || !_isNumber(args[1]))
    {
        _logError("bg: invalid arguments");
        return;
    }
    JobsList::JobEntry* move_bg_job;
    if (this->argc == 1)
    { // resume last stopped
        move_bg_job = this->jobs->getLastStoppedJob();
        if (!move_bg_job)
        {
            _logError("bg: there is no stopped jobs to resume");
            return;
        }
    }
    else
    { // argc = 2
       
       
        const unsigned int req_job_id = stoi(args[1]);
        move_bg_job = this->jobs->getJobById(req_job_id);
        if (!move_bg_job)
        {            
            _logError("bg: job-id " + to_string(req_job_id) + " does not exist");
            return;
        }
        else if (!move_bg_job->job_stopped)
        { // already running in the background
            
            _logError("bg: job-id " + to_string(req_job_id) + " is already running in the background");
            return;
        }
    }
    pid_t job_pid = move_bg_job->pid;

    if (kill(job_pid, SIGCONT) == -1)
    {
        _logError("bg: kill failed");
        return;
    }
    cout << move_bg_job->cmd << " : " << job_pid;
    move_bg_job->job_stopped = false; // job was resumed
}
void ExternalCommand::execute()
{
    int stat;
    pid_t parent_pid = getpid();

    char * bash_args= "-c";
    char * bash_bin = "/bin/bash";
    char *arguments[] = {bash_bin, bash_args, this->cmd_line_wo_ampersand, nullptr};
    pid_t pid; 
    DO_SYS_VAL(fork(),pid);
    if (getpid() == parent_pid)
    { // parent
        if(is_background)
        {
             this->jobs->addJob(this, pid, false);
        }
        else
        {
            DO_SYS(wait(&stat));
        }      
    }
    else
    { // child
        setpgrp();
        DO_SYS(execve("/bin/bash", arguments, NULL));        
    }
}

void CatCommand::execute()
{
    if(argc ==1)
    {
        _logError("cat: not enough arguements");
        return;
    }
    for (unsigned short i = 1; i < argc; i++)
    {
        int ch_buffer;
        const char* file_path = args[i];
        int fd;
        DO_SYS_VAL_NO_RETURN(open(file_path,O_RDONLY),fd);
        if(fd!=-1)
        {
            while(read(fd,&ch_buffer,1)) // Read bytes one by one
            {
                int write_status;
                DO_SYS_VAL_NO_RETURN(write(STDOUT_FILENO,&ch_buffer,1),write_status);
                if(write_status<0) 
                    break; // Continue to next file
            }
		    close(fd);                          
        }
        
    }
    
}


void RedirectionCommand::checkRedirectType() {
    std::string override_right = ">";
    std::string append_right = ">>";

    string cmd_str = string(cmd_line);
    string output_file;
    this->redirect = APPEND_RIGHT;
    std::string command = cmd_str.substr(0, cmd_str.find(append_right)); // token is "scott"
    if( command == cmd_str)
    {// Try to findout if overwrite
        this->redirect = OVERRIDE_RIGHT;
        command = cmd_str.substr(0, cmd_str.find(override_right));
        output_file =  cmd_str.substr(1, cmd_str.find(override_right));
    }
    else
    {
        return;
    }
    //std::string output_file = cmd_line.substr(, cmd_line.find(append_right)); // token is "scott"

}
/*
void RedirectionCommand::checkRedirectType() {
    string str(cmd_line);
    std::string override_right = ">";
    std::string append_right = ">>";
    std::string override_left = "<";
    std::string append_left = "<<";
    string delimiter;
    int pos = 0;
    int temp_pos = 0;

    if ((temp_pos = str.find(append_right, pos)) != std::string::npos){
        pos = temp_pos;
        this->redirect = APPEND_RIGHT;
        first_command = str.substr(0);
        delimiter = append_right;
    }
    else if ((temp_pos = str.find(override_right)) != std::string::npos){
        pos = temp_pos;
        this->redirect = OVERRIDE_RIGHT;
        first_command = str.substr(0, pos);
        delimiter = override_right;
    }
    else if ((temp_pos = str.find(append_left)) != std::string::npos){
        pos = temp_pos;
        this->redirect = APPEND_LEFT;
        first_command = str.substr(0, pos);
        delimiter = append_left;
    }
    else if ((temp_pos = str.find(override_left)) != std::string::npos){
        pos = temp_pos;
        this->redirect = OVERRIDE_LEFT;
        first_command = str.substr(0, pos);
        delimiter = override_left;
    }
    else {
        return;// CHECK!!!
    }
    second_output_file = str.erase(0, pos + delimiter.length()); //CHECK WHAT ABOUT & ?
    second_output_file.erase(remove(second_output_file.begin(), second_output_file.end(), '&'), second_output_file.end());// to do or not to do ???????????
}
*/
RedirectionCommand::RedirectionCommand(const char *cmd_line, SmallShell* shell) : Command(cmd_line), redirect(APPEND_RIGHT), shell(shell){
    checkRedirectType();
}

void RedirectionCommand::execute() {
    pid_t parent_pid = getpid();
    pid_t pid;
    const char * test = second_output_file.data();
    const char * test2 = second_output_file.c_str();
    DO_SYS_VAL(fork(),pid);
    if (getpid() == parent_pid)
    { // parent
        waitpid(pid,NULL, -1);
    }
    else { // child
        setpgrp();
        int new_fd;
        if (this->redirect == OVERRIDE_RIGHT || this->redirect == APPEND_RIGHT){
            if (this->redirect == OVERRIDE_RIGHT){
                DO_SYS_VAL_NO_RETURN(open("test.txt",O_WRONLY | O_CREAT | O_TRUNC, 0666),new_fd);
            }
            else { // APPEND_RIGHT
                DO_SYS_VAL_NO_RETURN(open(second_output_file.c_str(),O_WRONLY | O_CREAT | O_APPEND, 0666), new_fd);
            }
            close(1); // STDOUT
            this->shell->executeCommand(first_command.c_str());
            close(new_fd);
        }
        else if (this->redirect == OVERRIDE_LEFT || this->redirect == APPEND_LEFT){
            if (this->redirect == OVERRIDE_RIGHT){
                DO_SYS_VAL_NO_RETURN(open(second_output_file.c_str(),O_WRONLY | O_CREAT | O_TRUNC, 0666),new_fd);
            }
            else { // APPEND_RIGHT
                DO_SYS_VAL_NO_RETURN(open(second_output_file.c_str(),O_WRONLY | O_CREAT | O_APPEND, 0666), new_fd);
            }
            close(0); // STDIN
            this->shell->executeCommand(first_command.c_str());
            close(new_fd); // close file
        }
        exit(0); // kill child ?
    }
}
vector<string> _stringSplit(string str,const string delimiter)
{
    size_t pos = 0;
   
    vector<string> segments;
    while ((pos = str.find(delimiter)) != std::string::npos)
    {
        segments.push_back(str.substr(0, pos));     
        str.erase(0, pos + delimiter.length());
    }
     segments.push_back(str);  
     return segments;   
}
PipeCommand::PipeCommand(const char *cmd_line) : Command(cmd_line), stderr_pipe(false)
{
    string command_str = string(cmd_line);
    std::string pipe = "|";
    std::string pipe_stderr = "|&";

    vector<string> pipe_segments = _stringSplit(command_str,pipe);
    vector<string> pipe_stderr_segments = _stringSplit(command_str,pipe_stderr);
    vector<string> * pipe_segments_p;
    this->stderr_pipe = (pipe_stderr_segments.size() == 2);
    pipe_segments_p = stderr_pipe ? &pipe_stderr_segments : &pipe_segments;
    
    this->command_arguement = (*pipe_segments_p).at(0);
    this->piped_arguement = (*pipe_segments_p).at(1);
}
void PipeCommand::execute()
{
    
}