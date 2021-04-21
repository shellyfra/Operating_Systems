#ifndef SMASH_COMMAND_H_
#define SMASH_COMMAND_H_

#include <vector>
#include <time.h>
#include <string.h>

#define COMMAND_ARGS_MAX_LENGTH (200)
#define COMMAND_MAX_ARGS (20)
#define COMMAND_MAX_LENGTH (80)

#define WHITESPACE ' '
#define DEFAULT_PROMPT "smash"
#define SHOW_PID_COMMAND_STR "showpid"
#define PRINT_WORKING_DIRECTORY_STR "pwd"
#define CHANGE_DIRECTORY_COMMAND_STR "cd"
#define CHANGE_DIRECTORY_LAST_ARG '-'
#define CHANGE_PROMPT_COMMAND_STR "chprompt"
#define JOBS_COMMAND_STR "jobs"
#define FOREGROUND_COMMAND_STR "fg"
#define KILL_COMMAND_STR "kill"
#define QUIT_COMMAND_STR "quit"
#define BG_COMMAND_STR "bg"
#define JOB_ID_INITIAL_VALUE (0)
#define EXTERNAL_CMD_ARGS_COUNT (3)



#define DO_SYS(syscall)                   \
    do                                    \
    {                                     \
        /* safely invoke a system call */ \
        if ((syscall) == -1)              \
        {                                 \
            perror(#syscall);             \
            return;                       \
        }                                 \
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
    const char * GetCmd() const {return this->cmd_line;}
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

class RedirectionCommand : public Command
{
    // TODO: Add your data members
public:
    explicit RedirectionCommand(const char *cmd_line);
    virtual ~RedirectionCommand() {}
    void execute() override;
    //void prepare() override;
    //void cleanup() override;
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
        JobEntry() : cmd(nullptr), job_id(0), pid(0), start_time(time(NULL)), job_stopped(false) {} // cmd = null -> mask empty JobEntry
        ~JobEntry() = default;
        JobEntry(JobEntry const &) = default; // CHECK!
        //JobEntry &operator=(const JobEntry &JobEntry);
        //JobEntry & operator=(JobEntry & other) {return  }
        JobEntry& operator=(const JobEntry& other);  // check!
      
        const bool IsEmpty() const {return (cmd == nullptr);}
        friend std::ostream &operator<<(std::ostream &, const JobEntry &);

        // TODO: Add your data members
    };

private:
    std::vector<JobEntry> jobs_list;

    // TODO: Add your data members
public:
    JobsList() = default;
//    JobsList()
//    {
//        Command* cmd1 = new GetCurrDirCommand("pwd 1");
//        Command* cmd2 = new GetCurrDirCommand("pwd 2");
//        Command* cmd3 = new GetCurrDirCommand("pwd 3");
//        jobs_list.push_back(JobEntry(cmd1, 2, 1000, true));
//        jobs_list.push_back(JobEntry(cmd2, 4, 2000, false));
//        jobs_list.push_back(JobEntry(cmd3, 6, 2000, false));
//    }
    ~JobsList() = default;
    JobsList& operator=(const JobsList& other) = default; // for now
    void addJob(Command *cmd, pid_t child_pid, const bool &isStopped = false); // Done
    void printJobsList() const; // Done
    void killAllJobs();                            // Done
    const unsigned int removeFinishedJobs();                     // Done
    JobEntry getJobById(const unsigned int & jobId) const;         //Done
    void removeJobById(const unsigned int &jobId);                 // Done
    JobEntry getLastJob() const;    //Done, For fg or for figuring out what is the maximal ID
    JobEntry getLastStoppedJob() ; // For bg , Shai
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
    virtual ~ExternalCommand() =default;
    void execute() override;
};

class QuitCommand : public BuiltInCommand
{

   bool &should_run;
    JobsList *jobs; // Not const since will remove jobs
public:
    QuitCommand(const char *cmd_line, JobsList *jobs , bool & should_run) : BuiltInCommand(cmd_line) ,should_run(should_run), jobs(jobs) {}
    virtual ~QuitCommand() {}
    void execute() override;
};

class JobsCommand : public BuiltInCommand
{
    JobsList *jobs; // Not const since will remove jobs
public:
    JobsCommand(const char *cmd_line, JobsList *jobs ) : BuiltInCommand(cmd_line) , jobs(jobs)  {}
    virtual ~JobsCommand() {}
    void execute() override;
};

class KillCommand : public BuiltInCommand
{
    JobsList *jobs;
public:
    KillCommand(const char *cmd_line, JobsList *jobs) : BuiltInCommand(cmd_line) , jobs(jobs) {}
    virtual ~KillCommand() {}
    void execute() override;
};

class ForegroundCommand : public BuiltInCommand
{
    JobsList *jobs;
public:
    ForegroundCommand(const char *cmd_line, JobsList *jobs) : BuiltInCommand(cmd_line) , jobs(jobs) {}
    virtual ~ForegroundCommand() {}
    void execute() override;
};

class BackgroundCommand : public BuiltInCommand
{
    // TODO: Add your data members
    JobsList *jobs;
public:
    BackgroundCommand(const char *cmd_line, JobsList *jobs) : BuiltInCommand(cmd_line) , jobs(jobs) {}
    virtual ~BackgroundCommand() {}
    void execute() override;
};

class CatCommand : public BuiltInCommand
{
public:
    CatCommand(const char *cmd_line);
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

    SmallShell() : should_run(true) ,  last_wd(nullptr) ,prompt_name(DEFAULT_PROMPT), jobs_list(new JobsList()) {}

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
    void changePrompt(const char *cmd_line);
    std::string getPromptName();
     bool & ShouldRun() {return this->should_run;} 
};

#endif //SMASH_COMMAND_H_
