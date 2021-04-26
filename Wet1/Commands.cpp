#include <unistd.h>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <sys/wait.h>

#include <ctype.h>
#include <fcntl.h>
#include <algorithm>
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

enum CHECK_TYPE{CHECK_POSITIVE, CHECK_NEGATIVE, NONE};
const string GetCurrentWorkingDirectory();
string _ltrim(const string &s);
string _rtrim(const string &s);
string _trim(const string &s);

int _parseCommandLine(const char *cmd_line, char **args);
bool _isBackgroundCommand(const char *cmd_line);
void _removeBackgroundSign(char *cmd_line);
static bool _isNumber(char *str, CHECK_TYPE check);
vector<string> _stringSplit(string str, const string delimiter);

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

int _parseCommandLine(const char *cmd_line, char **args)
{
    FUNC_ENTRY()
    int i = 0;

    std::istringstream iss(_trim(string(cmd_line)).c_str());
    for (string s; iss >> s;)
    {
        args[i] = (char *)malloc(s.length() + 1);
        memset(args[i], 0, s.length() + 1); // Make 's.length() + 1' bytes of zero
        strcpy(args[i], s.c_str());         // Copy the argument
        args[++i] = NULL;
    }
    return i;

    FUNC_EXIT()
}

bool _isBackgroundCommand(const char *cmd_line)
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
static bool _isNumber(char *str, CHECK_TYPE check = NONE)
{
    char *it = str;
    bool has_minus = false;
    while (char current = (*it++))
    {
        if (!std::isdigit(current))
        {
            if ((check == CHECK_POSITIVE) || ((check == CHECK_NEGATIVE) && (current != MINUS_SIGN))){
                return false;
            }
            has_minus = (current == MINUS_SIGN);
        }
    }
    if (check == CHECK_NEGATIVE){
        return has_minus;
    }
    return true;
}
Command::Command(const char *usr_cmd_line) : cmd_line(new char[COMMAND_MAX_LENGTH]), cmd_line_wo_ampersand(new char[COMMAND_MAX_LENGTH])
{

    strcpy(this->cmd_line, usr_cmd_line);
    strcpy(this->cmd_line_wo_ampersand, usr_cmd_line);
    this->args = (char **)malloc(sizeof(char *) * COMMAND_MAX_ARGS);
    this->argc = _parseCommandLine(cmd_line_wo_ampersand, this->args);
    _removeBackgroundSign(cmd_line_wo_ampersand);
};
Command::~Command()
{
    for (int i = 0; i < argc; i++)
    {
        free(args[i]);
    }
    free(args);
    delete[] cmd_line;
    delete[] cmd_line_wo_ampersand;
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
    char *temp_cmd = new char[COMMAND_MAX_LENGTH + 1];
    strcpy(temp_cmd, cmd_line);
    _removeBackgroundSign(temp_cmd);
    string cmd_s = _trim(string(temp_cmd));
    delete[] temp_cmd;
    string firstWord = cmd_s.substr(0, cmd_s.find_first_of(" \n"));

    if (cmd_s.find('>') != std::string::npos)
    {
        return new RedirectionCommand(cmd_line, this);
    }
    else if (cmd_s.find('|') != std::string::npos) // Has pipe character
    {                                              // Includes also |&
        return new PipeCommand(cmd_line, this);
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
    else if (firstWord.compare(CAT_COMMAND_STR) == 0)
    {
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
    Command *cmd = (CreateCommand(cmd_line));
    if (cmd)
    {
        cmd->execute();
    }
    // delete cmd; -> Memory leak here! not being deleted, but also this deletes info for jobs
    if (!dynamic_cast<ExternalCommand*>(cmd) || (dynamic_cast<ExternalCommand*>(cmd) && !_isBackgroundCommand(cmd_line))){
        delete cmd;
    }
    // Please note that you must fork smash process for some commands (e.g., external commands....)
}

BuiltInCommand::BuiltInCommand(const char *cmd_line) : Command(cmd_line)
{
}
ExternalCommand::ExternalCommand(const char *cmd_line, JobsList *jobs) : Command(cmd_line), jobs(jobs)
{
    this->is_background = (_isBackgroundCommand(cmd_line));
}
TimeoutCommand::TimeoutCommand(const char *cmd_line, JobsList *jobs) : Command(cmd_line), jobs(jobs)
{
}
void TimeoutCommand::execute()
{
    if (argc < 3 || !_isNumber(args[1], CHECK_POSITIVE))
    {
        _logError("fg: invalid arguments");
    }
}
BuiltInCommand::~BuiltInCommand()
{
}

void ShowPidCommand::execute()
{
    cout << "smash pid is " << SmallShell::getInstance().shell_pid << endl;
}
void JobsCommand::execute()
{
    //jobs->removeFinishedJobs();
    jobs->printJobsList();
}
void _logError(std::string text, const bool &to_stdout)
{
    std::ostream &output_stream = to_stdout ? std::cout : std::cerr;
    string prefix = to_stdout ? STDOUT_PREFIX : ERROR_PREFIX;
    output_stream << prefix << ' ' << text << std::endl;
}
void ChangeDirCommand::execute()
{
    if (argc < 2)
    {
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
    // cd successful
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
    string suffix = job_entry.is_stopped ? " (stopped)" : EMPTY_STRING;
    os << '[' << job_entry.job_id << "] " << *(job_entry.cmd) << " : " << job_entry.pid << ' '
       << difftime(time(NULL), job_entry.start_time) << " secs" << suffix;
    return os;
}
void JobsList::printJobsList() const
{
    for (auto &job_entry : jobs_list)
    {
        cout << (*job_entry) << endl;
    }
}
/*
void JobsList::printSchedJobsList() const
{
    for (auto &job_entry : sched_jobs_list)
    {
        cout << (*job_entry) << endl;
    }
}
*/
const unsigned int JobsList::removeFinishedJobs(const bool &remove_scheduled)
{
    // Due to complexity concerns, move all vector to new vector
    unsigned int max_job_id = JOB_ID_INITIAL_VALUE;
    vector<JobEntry *> new_job_list;
    for (auto &job_entry : this->jobs_list)
    {

        int status;
        pid_t result = waitpid(job_entry->pid, &status, WNOHANG);
        if (result == 0)
        {
            // Child still alive
            if (remove_scheduled && time(NULL) >= job_entry->expiry_time && !job_entry->stopped_time)
            {

                _logError(string(job_entry->cmd->getCmd()) + " timed out!", true);
                int dummy;
                DO_SYS_VAL_NO_RETURN(kill(job_entry->pid, SIGKILL), dummy);
                delete job_entry->cmd;
                delete job_entry;
                continue;
            }
            // Keep job
            new_job_list.push_back(job_entry);
            unsigned int new_id = job_entry->job_id;
            if (new_id > max_job_id)
            {
                max_job_id = new_id;
            }
        }
        else
        {
            // child finished
            delete job_entry->cmd;
            delete job_entry;
        }
    }
    jobs_list = new_job_list;
     if (remove_scheduled && foreground_job && time(NULL) >= foreground_job->expiry_time)
            {
                _logError(string(foreground_job->cmd->getCmd()) + " timed out!", true);
                int dummy;
                DO_SYS_VAL_NO_RETURN(kill(foreground_job->pid, SIGKILL), dummy);
                // fg / execute will deallocate the foreground command
                delete foreground_job->cmd;
                delete foreground_job;
            }
    return  max_job_id;
     
}
void JobsList::evaluateAlarm() const
{
    time_t earliest = MAX_TIME;

    for (auto &job_entry : this->jobs_list)
    {
        if (job_entry->is_stopped)
        {
            continue;
        }
        int status;
        time_t job_sched_time = job_entry->expiry_time;
        pid_t result = waitpid(job_entry->pid, &status, WNOHANG);
        if (result == 0)
        { // Child still alive, check if expired
           // cout << "Comparing current time to job: ";
            //print_time(time(NULL));
            //print_time(job_sched_time);
            earliest = earliest > job_sched_time ? job_sched_time : earliest;
            /*
            if (time(NULL) >= job_sched_time)
            {
                _logError(string(entry->cmd->getCmd()) + " timed out!", true);
                int dummy;
                DO_SYS_VAL_NO_RETURN(kill(entry->pid, SIGKILL), dummy);
            }
            else
            {
                // found a job with later alarm time
                return job_sched_time;
            }
            */
        }
        else
        { // CHild is dead, will be cleared when removeFInished jobs is called
          //  cout << "oops! there's a dead child here: " << job_entry << endl;
        }

    }
    if(foreground_job)
    {
        earliest = earliest > foreground_job->expiry_time ? foreground_job->expiry_time : earliest;
    }
            const int duration = difftime(earliest,time(NULL));
        
        if (earliest == MAX_TIME)
        {
         //   cout << "No alarm scheduled!" << endl;
             alarm(0);
        }
        else if (duration <= 0)
        {
         //   cout << "Earliest has passed... error" << endl;
        }
        else
        {
            
          //  cout << "New alarm : ";
           // print_time(earliest);
             alarm(duration);
        }

       

    // jobs_list = new_job_list;
    /*
    return max_job_id;

    while (JobsList::JobEntry *entry = sched_jobs_list.back())
    {
        const time_t job_sched_time = (entry)->expiry_time;
        // new_alarm_t =job_sched_time> new_alarm_t ?  job_sched_time : new_alarm_t;
        int status;
        pid_t result = waitpid(entry->pid, &status, WNOHANG);
        if (result == 0)
        {
            cout << "Comparing current time to job: ";
            print_time(time(NULL));
            print_time(job_sched_time);

            // Child still alive, check if expired
            if (time(NULL) >= job_sched_time)
            {
                _logError(string(entry->cmd->getCmd()) + " timed out!", true);
                int dummy;
                DO_SYS_VAL_NO_RETURN(kill(entry->pid, SIGKILL), dummy);
            }
            else
            {
                // found a job with later alarm time
                return job_sched_time;
            }
        }
        else
        {
            cout << "oops! there's a dead child here: " << entry << endl;
        }
        sched_jobs_list.pop_back();
    }
    */
}
void SmallShell::evaluateAlarm()
{
    this->jobs_list->evaluateAlarm();
    //  vector<JobEntry *> new_job_list;
}
/*
void JobsList::removeScheduledJobs()
{
    // Due to complexity concerns, move all vector to new vector
    // time_t new_alarm_t =   for (auto &job_entry : this->jobs_list.)
    {
        if(job_entry->is_stopped){
            continue;
        }
        int status;
        pid_t result = waitpid(job_entry->pid, &status, WNOHANG);
        if (result == 0)
        { // Child still alive, check if expired
            cout << "Comparing current time to job: ";
            print_time(time(NULL));
            print_time(job_sched_time);

           
            if (time(NULL) >= job_sched_time)
            {
                _logError(string(entry->cmd->getCmd()) + " timed out!", true);
                int dummy;
                DO_SYS_VAL_NO_RETURN(kill(entry->pid, SIGKILL), dummy);
            }
            else
            {
                // found a job with later alarm time
                return job_sched_time;
            }
        }
        else
        {
            cout << "oops! there's a dead child here: " << entry << endl;
        }
    }
   // jobs_list = new_job_list;
    return max_job_id;

    while (JobsList::JobEntry *entry = sched_jobs_list.back())
    {
        const time_t job_sched_time = (entry)->expiry_time;
        // new_alarm_t =job_sched_time> new_alarm_t ?  job_sched_time : new_alarm_t;
        int status;
        pid_t result = waitpid(entry->pid, &status, WNOHANG);
        if (result == 0)
        {
            cout << "Comparing current time to job: ";
            print_time(time(NULL));
            print_time(job_sched_time);

            // Child still alive, check if expired
            if (time(NULL) >= job_sched_time)
            {
                _logError(string(entry->cmd->getCmd()) + " timed out!", true);
                int dummy;
                DO_SYS_VAL_NO_RETURN(kill(entry->pid, SIGKILL), dummy);
            }
            else
            {
                // found a job with later alarm time
                return job_sched_time;
            }
        }
        else
        {
            cout << "oops! there's a dead child here: " << entry << endl;
        }
        sched_jobs_list.pop_back();
    }
    vector<JobEntry *> new_job_list;
    while (JobsList::JobEntry *entry = sched_jobs_list.back())
    {
        const time_t job_sched_time = (entry)->expiry_time;
        // new_alarm_t =job_sched_time> new_alarm_t ?  job_sched_time : new_alarm_t;
        int status;
        pid_t result = waitpid(entry->pid, &status, WNOHANG);
        if (result == 0)
        {
            cout << "Comparing current time to job: ";
            print_time(time(NULL));
            print_time(job_sched_time);

            // Child still alive, check if expired
            if (time(NULL) >= job_sched_time)
            {
                _logError(string(entry->cmd->getCmd()) + " timed out!", true);
                int dummy;
                DO_SYS_VAL_NO_RETURN(kill(entry->pid, SIGKILL), dummy);
            }
            else
            {
                // found a job with later alarm time
                return job_sched_time;
            }
        }
        else
        {
            cout << "oops! there's a dead child here: " << entry << endl;
        }
        sched_jobs_list.pop_back();
    }
   
    return MAX_TIME;
}
*/
void JobsList::removeJobById(const unsigned int &jobId, bool to_delete)
{
    unsigned int count = 0;
    for (auto &job_entry : jobs_list)
    {
        if (job_entry->job_id == jobId)
        {
            delete job_entry;
            jobs_list.erase(jobs_list.begin() + count);
            if (to_delete){
                delete job_entry->cmd;
                delete job_entry;
            }
            return;
        }
        count++;
    }
}
JobsList::JobEntry *JobsList::getLastStoppedJob()
{
    for (auto job_entry = jobs_list.rbegin(); job_entry != jobs_list.rend(); ++job_entry)
    { // Consider creating array for pointer in order to support complexity of O(1)...
        if ((*job_entry)->is_stopped)
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
    if ((argc == 1) && !this->jobs->getLastJob()) // No jobs
    {
        _logError("fg: jobs list is empty");
    }
    else if (argc > 2 || (argc == 2 && !_isNumber(args[1])))
    {
        _logError("fg: invalid arguments");
    }
    else
    {
        const int job_id = argc == 2 ? std::stoi(args[1]) : jobs->getLastJob()->job_id;
        JobsList::JobEntry *job_entry = this->jobs->getJobById(job_id);
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

            cout << (*job_entry->cmd) << " : " << (job_entry->pid) << endl;
         
            time_t new_expiry = job_entry->expiry_time;
            if(job_entry->expiry_time != MAX_TIME && job_entry->is_stopped)
            {
               new_expiry=time(NULL)+ (job_entry->expiry_time-job_entry->stopped_time);
           //    cout << "New time for job: ";
               //print_time(new_expiry);
            }
            //this->jobs->addJob(job_entry->cmd, job_entry->pid, false, true,new_expiry); // Adde job to foreground
            // This ^ will do an alarm evaluation again
            //this->jobs->removeJobById(job_id);
            job_entry->expiry_time = new_expiry;
            jobs->foreground_job = job_entry;
            jobs->evaluateAlarm();
            int status;

            DO_SYS(waitpid(job_pid, &status, WSTOPPED));
            if (WIFSTOPPED(status))
            {
                // It stopped again
                time_t current_time = time(NULL);
                job_entry->is_stopped = true;
                job_entry->stopped_time = current_time;
                job_entry->start_time= current_time;
            }
            else
            {
                // Job is finished and was in job list before, therefor remove it
                jobs->removeJobById(job_entry->job_id, true);
                
            }
            // Parent handle will reach here after child has ended or stopped (due to control+Z),
            // So anywho we remove the foreground job so cntl+Z won't catch the foreground job again
           
            this->jobs->foreground_job = nullptr;
            
            jobs->evaluateAlarm();
        }
    }
}

JobsList::JobEntry *JobsList::addJob(Command *cmd, pid_t child_pid, const bool is_stopped, const bool foreground, const time_t expiry_time)
{

    unsigned int new_job_id = removeFinishedJobs() + 1;
    //Command *temp =new Command(cmd->getCmd());
    JobEntry *new_job = new JobEntry(cmd, new_job_id, child_pid, is_stopped, expiry_time);
    if (foreground)
    {
        this->foreground_job = new_job; // Won't be added to job_list
    }
    else
    {

        this->jobs_list.push_back(new_job);
    }
    if(expiry_time != MAX_TIME)
    {
        evaluateAlarm();
    }
    
    return new_job;
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
        delete job_entry->cmd;
        delete job_entry;
        count++;
    }
    jobs_list.clear();
}

JobsList::JobEntry *JobsList::getJobById(const unsigned int &jobId) const
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

JobsList::JobEntry *JobsList::getLastJob() const
{
    return jobs_list.empty() ? nullptr : jobs_list.back();
}

void JobsList::quitAllJobs() {
    for (auto &job_entry : this->jobs_list)
    {
//            if (kill(job_entry->pid, SIGKILL) != 0)
//            {
//                _logError("killAllJobs: kill job failed"); // CHECK with staff!
//                continue;                                  // not sure what to do here
//            }
//            DO_SYS(wait(NULL));
        delete job_entry->cmd;
        delete job_entry;
    }
}

void ChangePromptCommand::execute()
{
    *prompt_name_p = argc == 1 ? DEFAULT_PROMPT : args[1];
}
void KillCommand::execute()
{
    //parse args
    if (this->argc != 3 || !_isNumber(args[1], CHECK_NEGATIVE) || stoi(args[1]) >= 0 || !_isNumber(args[2]))
    {
        _logError("kill: invalid arguments");
        return;
    }
    const int signal_num = stoi(args[1]) * -1;
    const int req_job_id = stoi(args[2]);

    JobsList::JobEntry *entry = jobs->getJobById(req_job_id);
    if (!entry)
    {
        std::string message = "kill: job-id " + to_string(req_job_id) + " does not exist";
        _logError(message);
        return;
    }
    //DO_SYS(kill(entry->pid, int(first_arg.at(0)))); // Won't work if signal is above 9..
    DO_SYS(kill(entry->pid, signal_num));
    cout << "signal number " << signal_num << " was sent to pid " << entry->pid << endl;
    switch (signal_num)
    {
    case SIGCONT:
        entry->is_stopped = false;
        SmallShell::getInstance().evaluateAlarm();
        break;
    case SIGSTOP:
        entry->is_stopped = true;
        SmallShell::getInstance().evaluateAlarm();
        break;
        case SIGKILL:
        
        SmallShell::getInstance().evaluateAlarm();
        break;
    }
}
/*
void KillCommand::ToForeground(JobsList::JobEntry* entry){
    pid_t job_pid = entry->pid;
    //DO_SYS(kill(job_pid, SIGCONT)); - already DONE!!
// SIGCONT succeeded
    if (!entry->is_stopped) return; // if running in foreground - do nothing
    this->jobs->addJob(entry->cmd,entry->pid,false,true); // Add job to foreground
    this->jobs->removeJobById(job_pid);

    DO_SYS(waitpid(job_pid,NULL,WSTOPPED));
    // Parent handle will reach here after child has ended or stopped (due to control+Z),
    // So anywho we remove the foreground job so cntl+Z won't catch the foreground job again
    delete(this->jobs->foreground_job);
    this->jobs->foreground_job = nullptr;
}
*/
void QuitCommand::execute()
{

    if (argc >= 2 && strcmp(args[1], "kill") == 0)
    {
        jobs->killAllJobs();
        while (waitpid(-1, NULL, WNOHANG) != -1)
            ;
    }
    else {
        jobs->quitAllJobs();
    }
    should_run = false;
}

void BackgroundCommand::execute()
{

    if (this->argc > 2 || (this->argc == 2 && !_isNumber(args[1])))
    {
        _logError("bg: invalid arguments");
        return;
    }
    JobsList::JobEntry *move_bg_job;
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

        const int req_job_id = stoi(args[1]);
        move_bg_job = this->jobs->getJobById(req_job_id);
        if (!move_bg_job)
        {
            _logError("bg: job-id " + to_string(req_job_id) + " does not exist");
            return;
        }
        else if (!move_bg_job->is_stopped)
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
    cout << *(move_bg_job->cmd) << " : " << job_pid << endl;
    move_bg_job->is_stopped = false; // job was resumed
    if(move_bg_job->expiry_time != MAX_TIME)
    {
        //This was scheduled
        move_bg_job->expiry_time=time(NULL)+ (move_bg_job->expiry_time-move_bg_job->stopped_time);
        jobs->evaluateAlarm();
    }
    
}
/*
void print_time(const time_t new_alarm)
{

    std::tm *ptm = std::localtime(&new_alarm);
    char buffer[32];
    // Format: Mo, 15.06.2009 20:20:00
    std::strftime(buffer, 32, "%a, %d.%m.%Y %H:%M:%S", ptm);
    puts(buffer);
}
*/
void ExternalCommand::execute()
{
    int stat;
    pid_t parent_pid = getpid();
    pid_t pid;
    string s = string(bash_bin);
    

    char *cmd_to_bash = this->cmd_line_wo_ampersand;
    time_t new_alarm_t = MAX_TIME;
    unsigned int duration = 0;
    if (argc >= 2 && strcmp(args[0], TIMEOUT_COMMAND_STR) == 0 && _isNumber(args[1])) // CHECK IF ADD TO IS_NUMBER = CHECK_POSITIVE
    {
        duration = stoi(string(args[1]));
        const string duration_str = to_string(duration);

        cmd_to_bash += string(cmd_to_bash).find_first_of(duration_str, 0) + strlen(duration_str.c_str());
        new_alarm_t = time(NULL) + duration;
      
    }
    DO_SYS_VAL(fork(), pid);
    if (getpid() == parent_pid)
    { // parent
        JobsList::JobEntry* job;
        this->jobs->addJob(this, pid, false, !is_background, new_alarm_t); // This is temp for cntrol+Z
        if (!is_background)
        {

            DO_SYS(waitpid(pid, &stat, WSTOPPED));
            // Parent handle will reach here after child has ended or stopped (due to control+Z),
            // So anywho we remove the foreground job so cntl+Z won't catch the foreground job again
            if (WIFSTOPPED(stat))
            { // Properly add it to jobs list to allocate job id and time
            
                job = this->jobs->addJob(this, pid, true,false, new_alarm_t);
                job->stopped_time = time(NULL);             
            }
            // Remove temp foreground job
            delete (this->jobs->foreground_job);
            this->jobs->foreground_job = nullptr;
            this->jobs->removeJobById(job->job_id, true);

           if(duration!= 0)
           {
                jobs->evaluateAlarm();
           }
            
        }
    }
    else
    { // child
        setpgrp();

        char *const arguments[] = {(char *)bash_bin, (char *)bash_args, cmd_to_bash, nullptr};
        DO_SYS(execve(bash_bin, arguments, NULL));
    }
}

void CatCommand::execute()
{
    if (argc == 1)
    {
        _logError("cat: not enough arguments");
        return;
    }
    for (unsigned short i = 1; i < argc; i++)
    {
        int ch_buffer;
        const char *file_path = args[i];
        string new_file_path = file_path;
        _trim(new_file_path);
        int fd;
        DO_SYS_VAL_NO_RETURN(open(new_file_path.c_str(), O_RDONLY), fd);
        if (fd != -1)
        {
            while (read(fd, &ch_buffer, 1)) // Read bytes one by one
            {
                int write_status;
                DO_SYS_VAL_NO_RETURN(write(STDOUT_FILENO, &ch_buffer, 1), write_status);
                if (write_status < 0)
                    break; // Continue to next file
            }
            close(fd);
        }
    }
}

// This is called only once, shouldn't we just put this in the redirection constructor?
void RedirectionCommand::checkRedirectType()
{
    string str(cmd_line);
    std::string override_right = ">";
    std::string append_right = ">>";
    std::string override_left = "<";
    std::string append_left = "<<";
    string delimiter;
    int pos = 0;
    int temp_pos = 0;
    const int npos = -1;

    if ((temp_pos = str.find(append_right, pos)) != npos)
    {
        pos = temp_pos;
        this->redirect = APPEND_RIGHT;
        first_command = str.substr(0, pos);
        //pos +=1;
        delimiter = append_right;
    }
    else if ((temp_pos = str.find(override_right)) != npos)
    {
        pos = temp_pos;
        this->redirect = OVERRIDE_RIGHT;
        first_command = str.substr(0, pos);
        delimiter = override_right;
    }
    else if ((temp_pos = str.find(append_left)) != npos)
    {
        pos = temp_pos;
        this->redirect = APPEND_LEFT;
        first_command = str.substr(0, pos);
        //pos +=1; // for second >
        delimiter = append_left;
    }
    else if ((temp_pos = str.find(override_left)) != npos)
    {
        pos = temp_pos;
        this->redirect = OVERRIDE_LEFT;
        first_command = str.substr(0, pos);
        delimiter = override_left;
    }
    else
    {
        return; // CHECK!!!
    }

    second_output_file = str.erase(0, pos + delimiter.length()); //CHECK WHAT ABOUT & ?
    second_output_file.erase(remove(second_output_file.begin(), second_output_file.end(), '&'), second_output_file.end());
}

RedirectionCommand::RedirectionCommand(const char *cmd_line, SmallShell *shell) : Command(cmd_line), redirect(APPEND_RIGHT), shell(shell)
{
    checkRedirectType();

    /*
    string command_str = string(cmd_line);
    std::string pipe = ">";
    std::string pipe_stderr = ">>";

    vector<string> pipe_segments = _stringSplit(command_str, pipe);
    vector<string> pipe_stderr_segments = _stringSplit(command_str, pipe_stderr);
    vector<string> *pipe_segments_p;
    this->redirect = (pipe_stderr_segments.size() == 2) ? Redirect_type::APPEND_RIGHT : Redirect_type::OVERRIDE_RIGHT;
    pipe_segments_p = redirect == APPEND_RIGHT ? &pipe_stderr_segments : &pipe_segments;

    this->first_command = (*pipe_segments_p).at(0);
    this->second_output_file = (*pipe_segments_p).at(1);
    */
}

void RedirectionCommand::execute()
{
    int old_fd;
    int new_fd;
    second_output_file = _trim(second_output_file);
    const int oflags = ((this->redirect == OVERRIDE_RIGHT) || (this->redirect == OVERRIDE_LEFT))
                           ? (O_WRONLY | O_CREAT | O_TRUNC)
                           : (O_WRONLY | O_CREAT | O_APPEND);
    const int std_channel = ((this->redirect == OVERRIDE_RIGHT) || (this->redirect == APPEND_RIGHT))
                                ? STDOUT_FILENO
                                : STDIN_FILENO;

    DO_SYS_VAL_NO_RETURN(dup(std_channel), old_fd);
    DO_SYS(close(std_channel)); // STDOUT
    DO_SYS_VAL_NO_RETURN(open(second_output_file.c_str(), oflags, 0666), new_fd);
    this->shell->executeCommand(first_command.c_str());
    DO_SYS(close(new_fd));
    DO_SYS(dup2(old_fd, std_channel));
    DO_SYS(close(old_fd));
}

vector<string> _stringSplit(string str, const string delimiter)
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
PipeCommand::PipeCommand(const char *cmd_line, SmallShell *shell) : Command(cmd_line), shell(shell), stderr_pipe(false)
{
    string command_str = string(cmd_line);
    std::string pipe = "|";
    std::string pipe_stderr = "|&";

    vector<string> pipe_segments = _stringSplit(command_str, pipe);
    vector<string> pipe_stderr_segments = _stringSplit(command_str, pipe_stderr);
    vector<string> *pipe_segments_p;
    this->stderr_pipe = (pipe_stderr_segments.size() == 2);
    pipe_segments_p = stderr_pipe ? &pipe_stderr_segments : &pipe_segments;

    this->command_arguement = (*pipe_segments_p).at(0);
    this->piped_arguement = (*pipe_segments_p).at(1);
}
void PipeCommand::execute()
{
    // These will delete themselves
    std::shared_ptr<Command> command1_p(shell->CreateCommand(command_arguement.c_str()));
    std::shared_ptr<Command> command2_p(shell->CreateCommand(piped_arguement.c_str()));

    //int saved_stdout = dup(STDOUT_FILENO);
    int fd[2];
    DO_SYS(pipe(fd)); // fd is now populated
    pid_t parent_pid = getpid();
    pid_t pid1;
    pid_t pid2;
    DO_SYS_VAL(fork(), pid1);
    if (parent_pid == getpid())
    { // Parent
        DO_SYS_VAL(fork(), pid2);
        if (parent_pid == getpid())
        {
            // Parent will get here, restore channels
            DO_SYS(close(fd[STDOUT_FILENO]));
            DO_SYS(close(fd[STDIN_FILENO]));
            int status;
            DO_SYS(waitpid(pid1, &status, 0));
            DO_SYS(waitpid(pid2, &status, 0));
        }
        else
        { // second child
            setpgrp();
            DO_SYS(close(fd[0]));                                             //close read from pipe, in parent
            DO_SYS(dup2(fd[1], stderr_pipe ? STDERR_FILENO : STDOUT_FILENO)); // Replace stdout with the write end of the pipe
            DO_SYS(close(fd[1]));                                             // Don't need another copy of the pipe write end hanging about
            command1_p->execute();
            exit(1);
        }
    }
    else
    { // Child
        setpgrp();
        DO_SYS(close(fd[1]));              //close write to pipe, in child
        DO_SYS(dup2(fd[0], STDIN_FILENO)); // Replace stdin with the read end of the pipe
        DO_SYS(close(fd[0]));              // Don't need another copy of the pipe read end hanging about
        command2_p->execute();
        exit(1);
    }
}
