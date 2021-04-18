#ifndef SMASH_COMMAND_H_
#define SMASH_COMMAND_H_

#include <vector>
#include <time.h>

#define COMMAND_ARGS_MAX_LENGTH (200)
#define COMMAND_MAX_ARGS (20)

#define WHITESPACE ' '
#define DEFAULT_PROMPT "smash"
#define SHOW_PID_COMMAND_STR "showpid"
#define PRINT_WORKING_DIRECTORY_STR "pwd"
#define CHANGE_DIRECTORY_COMMAND_STR "cd"
#define CHANGE_DIRECTORY_LAST_ARG '-'
#define CHANGE_PROMPT_COMMAND_STR "chprompt"
#define JOBS_COMMAND_STR "jobs"
#define JOB_ID_INITIAL_VALUE 1
//#define PWD_PATH_START_SIZE 150

class Command
{
  // TODO: Add your data members
  const char *cmd_line;

public:
  Command(const char *cmd_line) : cmd_line(cmd_line){};
  virtual ~Command() = default;
  virtual void execute() = 0;
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

class ExternalCommand : public Command
{
public:
  ExternalCommand(const char *cmd_line);
  virtual ~ExternalCommand() {}
  void execute() override;
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
class QuitCommand : public BuiltInCommand
{
  // TODO: Add your data members public:
  QuitCommand(const char *cmd_line, JobsList *jobs);
  virtual ~QuitCommand() {}
  void execute() override;
};

class JobsList
{

public:
  class JobEntry
  {
  private:
    const Command *cmd;
    const unsigned int job_id;
    const unsigned int pid;
    const time_t start_time;
    bool job_stopped;
    JobEntry(const Command *cmd, const unsigned int job_id, const unsigned int pid, const bool is_stopped)
        : cmd(cmd), job_id(job_id), pid(pid), start_time(time(NULL)), job_stopped(is_stopped) {}
    ~JobEntry() = default;
  public:
    const unsigned int GetPid() const {return pid;}
    const unsigned int GetJobId() const {return job_id;}
    const bool IsStopped() const {return job_stopped;}
    friend std::ostream &operator<<(std::ostream &, const JobEntry &);

    // TODO: Add your data members
  };

private:
  std::vector<JobEntry> jobs_list;

  // TODO: Add your data members
public:
  JobsList() = default;
  ~JobsList();
  void addJob(Command *cmd,const bool &isStopped = false); // Shelly, don't forget to call removeFinishedJobs before adding
  void printJobsList() const; // Done
  void killAllJobs();                            // Shelly
  const unsigned int removeFinishedJobs();                     // Done
  JobEntry *getJobById(const unsigned int & jobId) const;         // Shelly
  void removeJobById(const unsigned int &jobId);                 // Done
  JobEntry *getLastJob(int *lastJobId) const;    // For fg or for figuring out what is the maximal ID, Shelly
  JobEntry *getLastStoppedJob(int *jobId) const; // For bg , Shai
  // TODO: Add extra methods or modify exisitng ones as needed
  // TODO add operators
};

class JobsCommand : public BuiltInCommand
{
  // TODO: Add your data members
  JobsList *jobs; // Not const since will remove jobs
public:
  JobsCommand(const char *cmd_line, JobsList *jobs) : BuiltInCommand(cmd_line) , jobs(jobs) {}
  virtual ~JobsCommand() {}
  void execute() override;
};

class KillCommand : public BuiltInCommand
{
  // TODO: Add your data members
public:
  KillCommand(const char *cmd_line, JobsList *jobs);
  virtual ~KillCommand() {}
  void execute() override;
};

class ForegroundCommand : public BuiltInCommand
{
  // TODO: Add your data members
public:
  ForegroundCommand(const char *cmd_line, JobsList *jobs);
  virtual ~ForegroundCommand() {}
  void execute() override;
};

class BackgroundCommand : public BuiltInCommand
{
  // TODO: Add your data members
public:
  BackgroundCommand(const char *cmd_line, JobsList *jobs);
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
  char *last_wd;
  std::string prompt_name;
  JobsList *jobs_list;

  SmallShell();

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
};

#endif //SMASH_COMMAND_H_
