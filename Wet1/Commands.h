#ifndef SMASH_COMMAND_H_
#define SMASH_COMMAND_H_

#include <vector>
#include <time.h>
#include <string.h>
#include <memory>
#include <climits>
#include <list>
#include "signals.h"
#include <limits>
#include <ctime>

const unsigned short COMMAND_ARGS_MAX_LENGTH = 200;
const unsigned short MAX_PROCESSES = 100;
const unsigned short COMMAND_MAX_ARGS = 20;
const unsigned short COMMAND_MAX_LENGTH = 80;
const unsigned short JOB_ID_INITIAL_VALUE = 0;

const char WHITESPACE = ' ';
const char MINUS_SIGN = '-';
const char BACKGROUND_IDENTIFIER = '&';
const char *const EMPTY_STRING = "";
const char *const DEFAULT_PROMPT = "smash";

const char *const bash_args = "-c";
const char *const bash_bin = "/bin/bash";

const char *const SHOW_PID_COMMAND_STR = "showpid";
const char *const PRINT_WORKING_DIRECTORY_STR = "pwd";

const char *const CHANGE_DIRECTORY_COMMAND_STR = "cd";
const char CHANGE_DIRECTORY_LAST_ARG = '-';

const char *const CHANGE_PROMPT_COMMAND_STR = "chprompt";
const char *const JOBS_COMMAND_STR = "jobs";
const char *const FOREGROUND_COMMAND_STR = "fg";
const char *const TIMEOUT_COMMAND_STR = "timeout";
const char *const KILL_COMMAND_STR = "kill";
const char *const QUIT_COMMAND_STR = "quit";
const char *const BG_COMMAND_STR = "bg";
const char *const CAT_COMMAND_STR = "cat";
const char *const ERROR_PREFIX = "smash error:";
const char *const STDOUT_PREFIX = "smash:";

const time_t MAX_TIME = std::numeric_limits<time_t>::max();
enum Redirect_type
{
    OVERRIDE_LEFT = 1,
    OVERRIDE_RIGHT,
    APPEND_LEFT,
    APPEND_RIGHT
};

#define DO_SYS(syscall)                                                                         \
    do                                                                                          \
    {                                                                                           \
        /* safely invoke a system call */                                                       \
        if ((syscall) == -1)                                                                    \
        {                                                                                       \
            std::string syscall_call = std::string(#syscall);                                   \
            std::string syscall_name = syscall_call.substr(0, syscall_call.find('('));          \
            std::string error_msg = std::string(ERROR_PREFIX) + ' ' + syscall_name + " failed"; \
            perror(error_msg.c_str());                                                          \
            return;                                                                             \
        }                                                                                       \
    } while (0)

#define DO_SYS_VAL(syscall, var)                                                                \
    do                                                                                          \
    {                                                                                           \
        /* safely invoke a system call */                                                       \
        var = (syscall);                                                                        \
        if (var == -1)                                                                          \
        {                                                                                       \
            std::string syscall_call = string(#syscall);                                        \
            std::string syscall_name = syscall_call.substr(0, syscall_call.find('('));          \
            std::string error_msg = std::string(ERROR_PREFIX) + ' ' + syscall_name + " failed"; \
            perror(error_msg.c_str());                                                          \
            return;                                                                             \
        }                                                                                       \
    } while (0)

#define DO_SYS_VAL_NO_RETURN(syscall, var)                                                      \
    do                                                                                          \
    {                                                                                           \
        /* safely invoke a system call */                                                       \
        var = (syscall);                                                                        \
        if (var == -1)                                                                          \
        {                                                                                       \
            std::string syscall_call = std::string(#syscall);                                   \
            std::string syscall_name = syscall_call.substr(0, syscall_call.find('('));          \
            std::string error_msg = std::string(ERROR_PREFIX) + ' ' + syscall_name + " failed"; \
            perror(error_msg.c_str());                                                          \
        }                                                                                       \
    } while (0)

void print_time(const time_t new_alarm);
void _logError(std::string text, const bool &to_stdout = false);
class JobsList;

class Command
{

protected:
    
    char **args;
    int argc;
    char *cmd_line;
    char *cmd_line_wo_ampersand;

public:
    bool should_delete;
    Command(const char *usr_cmd_line);
    virtual ~Command();
    virtual void execute() = 0;
    friend std::ostream &operator<<(std::ostream &, const Command &);
    const char *const getCmd() const { return cmd_line; };

};

class BuiltInCommand : public Command
{

public:
    BuiltInCommand(const char *cmd_line);
    virtual ~BuiltInCommand();
};
class SmallShell;
class PipeCommand : public Command
{
    SmallShell *shell;
    bool stderr_pipe;
    std::string command_arguement;
    std::string piped_arguement;

public:
    PipeCommand(const char *cmd_line, SmallShell *shell);
    virtual ~PipeCommand() {}
    void execute() override;
};

class TimeoutCommand : public Command
{
    bool is_background;
    JobsList *jobs;

public:
    TimeoutCommand(const char *cmd_line, JobsList *jobs);
    virtual ~TimeoutCommand() {}
    void execute() override;
};

class RedirectionCommand : public Command
{
    Redirect_type redirect;
    SmallShell *shell;

    std::string first_command;
    std::string second_output_file;

public:
    explicit RedirectionCommand(const char *cmd_line, SmallShell *shell);
    virtual ~RedirectionCommand() {}
    void execute() override;
    void checkRedirectType();
};

class ChangeDirCommand : public BuiltInCommand
{
private:
    char **plastPwd; // Won't change pointer, but will change string
    
public:
    ChangeDirCommand(const char *cmd_line, char **plastPwd) : BuiltInCommand(cmd_line), plastPwd(plastPwd) {}
    virtual ~ChangeDirCommand() {}
    void execute() override;
};

class GetCurrDirCommand : public BuiltInCommand
{
public:
    explicit GetCurrDirCommand(const char *cmd_line) : BuiltInCommand(cmd_line) {}
    virtual ~GetCurrDirCommand() {}
    void execute() override;
};

class ShowPidCommand : public BuiltInCommand
{
public:
    ShowPidCommand(const char *cmd_line) : BuiltInCommand(cmd_line){};
    virtual ~ShowPidCommand() {}
    void execute() override;
};

class JobsList
{

public:
    struct JobEntry
    {
        Command *cmd;
        unsigned int job_id;
        pid_t pid;
        time_t start_time;
        time_t expiry_time;
        bool timed_out;
        bool is_stopped;

    public:
        JobEntry(Command *cmd, const unsigned int job_id, const unsigned int pid, const bool is_stopped, const time_t expiry_time)
            : cmd(cmd), job_id(job_id), pid(pid), start_time(time(NULL)), expiry_time(expiry_time)
                                                            ,timed_out(false) ,is_stopped(is_stopped) {}
       
        ~JobEntry() = default;
        JobEntry(JobEntry const &) = delete;                 // Copy ctor
        JobEntry &operator=(const JobEntry &other) = delete; //Assignment operator!

        const bool IsEmpty() const { return (cmd == nullptr); }
        friend std::ostream &operator<<(std::ostream &, const JobEntry &);

       
    };

private:
    std::vector<JobEntry *> jobs_list;
   

  
public:
    JobEntry *foreground_job;

    JobsList() : foreground_job(nullptr){};
    ~JobsList() = default;
    JobsList &operator=(const JobsList &other) = default; 
    JobEntry *addJob(Command *cmd, pid_t child_pid, const bool is_stopped = false
                            , const bool foreground = false, const time_t expiry_time = MAX_TIME);
    void printJobsList() const;                                                                            
    void killAllJobs();
    void quitAllJobs();
    const unsigned int removeFinishedJobs(const bool &remove_scheduled = false);
    void evaluateAlarm() const;
    JobEntry *getJobById(const unsigned int &jobId) const; 
    void removeJobById(const unsigned int &jobId);        
    JobEntry *getLastJob() const;                        
    JobEntry *getLastStoppedJob();                        

};

class ExternalCommand : public Command
{
protected:
    bool is_background;
    JobsList *jobs;

public:
    ExternalCommand(const char *cmd_line, JobsList *jobs);
    virtual ~ExternalCommand(){};
    void execute() override;
};

class QuitCommand : public BuiltInCommand
{

    bool &should_run;
    JobsList *jobs; // Not const since will remove jobs
public:
    QuitCommand(const char *cmd_line, JobsList *jobs, bool &should_run) : BuiltInCommand(cmd_line), should_run(should_run), jobs(jobs) {}
    virtual ~QuitCommand() {}
    void execute() override;
};

class JobsCommand : public BuiltInCommand
{
    JobsList *jobs; // Not const since will remove jobs
public:
    JobsCommand(const char *cmd_line, JobsList *jobs) : BuiltInCommand(cmd_line), jobs(jobs) {}
    virtual ~JobsCommand() {}
    void execute() override;
};

class ChangePromptCommand : public BuiltInCommand
{
    std::string *prompt_name_p; // Not const since will remove jobs
public:
    ChangePromptCommand(const char *cmd_line, std::string *prompt_name_p) : BuiltInCommand(cmd_line), prompt_name_p(prompt_name_p) {}
    virtual ~ChangePromptCommand() {}
    void execute() override;
};

class KillCommand : public BuiltInCommand
{
    JobsList *jobs;

public:
    KillCommand(const char *cmd_line, JobsList *jobs) : BuiltInCommand(cmd_line), jobs(jobs) {}
    virtual ~KillCommand() {}
    void execute() override;
  
};

class ForegroundCommand : public BuiltInCommand
{
    JobsList *jobs;

public:
    ForegroundCommand(const char *cmd_line, JobsList *jobs) : BuiltInCommand(cmd_line), jobs(jobs) {}
    virtual ~ForegroundCommand() {}
    void execute() override;
};

class BackgroundCommand : public BuiltInCommand
{
    // TODO: Add your data members
    JobsList *jobs;

public:
    BackgroundCommand(const char *cmd_line, JobsList *jobs) : BuiltInCommand(cmd_line), jobs(jobs) {}
    virtual ~BackgroundCommand() {}
    void execute() override;
};

class CatCommand : public BuiltInCommand
{
public:
    CatCommand(const char *cmd_line) : BuiltInCommand(cmd_line) {}
    virtual ~CatCommand() {}
    void execute() override;
};

class SmallShell
{
private:
    bool should_run;
    char *last_wd;
    std::string prompt_name;
    std::vector<time_t> alarm_schedule;
    SmallShell() : should_run(true), last_wd(nullptr), prompt_name(DEFAULT_PROMPT), jobs_list(new JobsList()) {}

public:
    JobsList *jobs_list;    
    pid_t shell_pid;
    Command *CreateCommand(const char *cmd_line);
    SmallShell(SmallShell const &) = delete;     // disable copy ctor
    void operator=(SmallShell const &) = delete; // disable = operator
    void addAlarm(time_t new_alarm_t);
    const bool removeAlarm();
    static SmallShell &getInstance() // make SmallShell singleton
    {
        static SmallShell instance; // Guaranteed to be destroyed.
        // Instantiated on first use.

        return instance;
    }
    ~SmallShell();
    void executeCommand(const char *cmd_line);  
    std::string getPromptName();
    bool &ShouldRun() { return this->should_run; }
};

#endif //SMASH_COMMAND_H_
