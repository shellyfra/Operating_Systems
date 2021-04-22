#ifndef SMASH_COMMAND_H_
#define SMASH_COMMAND_H_

#include <vector>
#include <time.h>
#include <string.h>

const unsigned short COMMAND_ARGS_MAX_LENGTH = 200;
const unsigned short COMMAND_MAX_ARGS = 20;
const unsigned short COMMAND_MAX_LENGTH = 80;
const unsigned short JOB_ID_INITIAL_VALUE = 0;

const char WHITESPACE = ' ';
const char MINUS_SIGN = '-';
const char BACKGROUND_IDENTIFIER = '&';
const char *const EMPTY_STRING = "";
const char *const DEFAULT_PROMPT = "smash";

const char *const SHOW_PID_COMMAND_STR = "showpid";
const char *const PRINT_WORKING_DIRECTORY_STR = "pwd";

const char *const CHANGE_DIRECTORY_COMMAND_STR = "cd";
const char CHANGE_DIRECTORY_LAST_ARG = '-';

const char *const CHANGE_PROMPT_COMMAND_STR = "chprompt";
const char *const JOBS_COMMAND_STR = "jobs";
const char *const FOREGROUND_COMMAND_STR = "fg";
const char *const KILL_COMMAND_STR = "kill";
const char *const QUIT_COMMAND_STR = "quit";
const char *const BG_COMMAND_STR = "bg";
const char *const CAT_COMMAND_STR = "cat";
const char *const ERROR_PREFIX = "smash error: ";

enum Redirect_type {OVERRIDE_LEFT = 1, OVERRIDE_RIGHT, APPEND_LEFT, APPEND_RIGHT} ;

#define DO_SYS(syscall)                                                           \
    do                                                                            \
    {                                                                             \
        /* safely invoke a system call */                                         \
        if ((syscall) == -1)                                                      \
        {                                                                         \
            string syscall_call = string(#syscall);                               \
            string syscall_name = syscall_call.substr(0, syscall_call.find('(')); \
            string error_msg = string(ERROR_PREFIX) + syscall_name + " failed";   \
            perror(error_msg.c_str());                                            \
            return;                                                               \
        }                                                                         \
    } while (0)

#define DO_SYS_VAL(syscall, var)                                                  \
    do                                                                            \
    {                                                                             \
        /* safely invoke a system call */                                         \
        var = (syscall);                                                          \
        if (var == -1)                                                            \
        {                                                                         \
            string syscall_call = string(#syscall);                               \
            string syscall_name = syscall_call.substr(0, syscall_call.find('(')); \
            string error_msg = string(ERROR_PREFIX) + syscall_name + " failed";   \
            perror(error_msg.c_str());                                            \
            return;                                                               \
        }                                                                         \
    } while (0)

#define DO_SYS_VAL_NO_RETURN(syscall, var)                                                  \
    do                                                                            \
    {                                                                             \
        /* safely invoke a system call */                                         \
        var = (syscall);                                                          \
        if (var == -1)                                                            \
        {                                                                         \
            string syscall_call = string(#syscall);                               \
            string syscall_name = syscall_call.substr(0, syscall_call.find('(')); \
            string error_msg = string(ERROR_PREFIX) + syscall_name + " failed";   \
            perror(error_msg.c_str());                                            \
        }                                                                         \
    } while (0)
class Command
{
protected:
    // TODO: Add your data members
    char *cmd_line;
    char *cmd_line_wo_ampersand;

public:
    Command(const char *usr_cmd_line);
    virtual ~Command();
    virtual void execute() = 0;
    friend std::ostream &operator<<(std::ostream &, const Command &);
    //virtual void prepare();
    //virtual void cleanup();

    // TODO: Add your extra methods if needed
};

class BuiltInCommand : public Command
{
protected:
    char **args;
    int argc;

public:
    BuiltInCommand(const char *cmd_line);
    virtual ~BuiltInCommand();
};

class PipeCommand : public Command
{
    // TODO: Add your data members
public:
    PipeCommand(const char *cmd_line);
    virtual ~PipeCommand() {}
    void execute() override;
};
class SmallShell;
class RedirectionCommand : public Command
{
    // TODO: Add your data members
    Redirect_type redirect;
    SmallShell* shell;

    std::string first_command;
    std::string second_output_file;
public:
    explicit RedirectionCommand(const char *cmd_line, SmallShell* shell);
    virtual ~RedirectionCommand() {}
    void execute() override;
    //void prepare() override;
    //void cleanup() override;
    void checkRedirectType();
};

class ChangeDirCommand : public BuiltInCommand
{
private:
    char **plastPwd; // Won't change pointer, but will change string
    // TODO: Add your data members public:
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

class JobsList;

class JobsList
{

public:
    struct JobEntry
    {
        const Command *cmd;
        unsigned int job_id;
        pid_t pid;
        time_t start_time;
        bool job_stopped;

    public:
        JobEntry(const Command *cmd, const unsigned int job_id, const unsigned int pid, const bool is_stopped)
            : cmd(cmd), job_id(job_id), pid(pid), start_time(time(NULL)), job_stopped(is_stopped) {}
        //JobEntry() : cmd(nullptr), job_id(0), pid(0), start_time(time(NULL)), job_stopped(false) {} // cmd = null -> mask empty JobEntry
        ~JobEntry() = default;
        JobEntry(JobEntry const &) = delete;                 // Copy ctor
        JobEntry &operator=(const JobEntry &other) = delete; //Assignment operator!

        const bool IsEmpty() const { return (cmd == nullptr); }
        friend std::ostream &operator<<(std::ostream &, const JobEntry &);

        // TODO: Add your data members
    };

private:
    std::vector<JobEntry *> jobs_list;

    // TODO: Add your data members
public:
    JobsList() = default;
    ~JobsList() = default;
    JobsList &operator=(const JobsList &other) = default;                      // for now
    void addJob(Command *cmd, pid_t child_pid, const bool &isStopped = false); // Done
    void printJobsList() const;                                                // Done
    void killAllJobs();                                                        // Done
    const unsigned int removeFinishedJobs();                                   // Done
    JobEntry *getJobById(const unsigned int &jobId) const;                     //Done
    void removeJobById(const unsigned int &jobId);                             // Done
    JobEntry *getLastJob() const;                                              //Done, For fg or for figuring out what is the maximal ID
    JobEntry *getLastStoppedJob();                                             // For bg , Shai
    // TODO: Add extra methods or modify exisitng ones as needed
    // TODO add operators
};

class ExternalCommand : public Command
{
protected:
    bool is_background;
    JobsList *jobs;

public:
    ExternalCommand(const char *cmd_line, JobsList *jobs);
    virtual ~ExternalCommand() = default;
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
    JobsList *jobs_list;

    SmallShell() : should_run(true), last_wd(nullptr), prompt_name(DEFAULT_PROMPT), jobs_list(new JobsList()) {}

public:
    Command *CreateCommand(const char *cmd_line);
    SmallShell(SmallShell const &) = delete;     // disable copy ctor
    void operator=(SmallShell const &) = delete; // disable = operator
    static SmallShell &getInstance()             // make SmallShell singleton
    {
        static SmallShell instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    ~SmallShell();
    void executeCommand(const char *cmd_line);
    // TODO: add extra methods as needed
    //void changePrompt(const char *cmd_line);
    std::string getPromptName();
    bool &ShouldRun() { return this->should_run; }
};
bool checkRedirection(const char * cmd_line);

#endif //SMASH_COMMAND_H_
