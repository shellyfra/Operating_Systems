#include <iostream>
#include <signal.h>
#include <unistd.h>
#include "signals.h"
#include "Commands.h"

using namespace std;

void ctrlZHandler(int sig_num)
{
  _logError("got ctrl-Z",true);
  if (sig_num == SIGTSTP)
  {
    SmallShell &shell = SmallShell::getInstance();
    JobsList::JobEntry *entry = shell.jobs_list->foreground_job;
    if (entry)
    { // If there is a running child
      DO_SYS(kill(entry->pid, SIGSTOP));                  // SIGSTOP cannot be overriden
      shell.jobs_list->addJob(entry->cmd,entry->pid,true);// Add fg job to background
     _logError("process "+to_string(entry->pid) +" was stopped",true);
    }
  }
}

void ctrlCHandler(int sig_num)
{

  // TODO: SHelly
  exit(1);
}

void alarmHandler(int sig_num)
{
  // TODO: Add your implementation
}
