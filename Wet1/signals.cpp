#include <iostream>
#include <signal.h>
#include <unistd.h>
#include "signals.h"
#include "Commands.h"

using namespace std;

void ctrlZHandler(int sig_num)
{

  if (sig_num == SIGTSTP)
  {
    SmallShell &shell = SmallShell::getInstance();
    JobsList::JobEntry *entry = shell.jobs_list->foreground_job;
    if (entry)
    { // If there is a running child

      signal(SIGTSTP, SIG_DFL);      
      shell.jobs_list->addJob(entry->cmd,entry->pid,true);
      delete(shell.jobs_list->foreground_job);            
      shell.jobs_list->foreground_job = nullptr;
      kill(entry->pid, SIGTSTP);
      signal(SIGTSTP, ctrlZHandler);
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
