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
    _logError("got ctrl-Z",true);
    SmallShell &shell = SmallShell::getInstance();
    JobsList::JobEntry *entry = shell.jobs_list->foreground_job;
   
    if (entry)
    { // If there is a running child
     pid_t pid = entry->pid;
      DO_SYS(kill(pid, SIGSTOP));                  // SIGSTOP cannot be overriden
      shell.jobs_list->addJob(entry->cmd,pid,true);// Add fg job to background
     _logError("process "+to_string(pid) +" was stopped",true);
    }
  }
}
void ctrlCHandler(int sig_num) {
    // possible only to external commands - SHOULD CHANGE ??
    if(sig_num == SIGINT)
    {
        _logError("got ctrl-C",true);
        SmallShell &smash = SmallShell::getInstance();

        //  See the fix i did for cntrlZ with the foreground job member - you da best
        JobsList::JobEntry * entry = smash.jobs_list->foreground_job;

        if(entry){
            pid_t pid = entry->pid;
            kill(pid, SIGKILL);                       // SIGSTOP cannot be overriden
            _logError("process "+to_string(pid) +" was killed",true);
        }
    }
}

void alarmHandler(int sig_num) {
    if(sig_num == SIGALRM) {
        cout << "smash got an alarm" << endl;
        SmallShell &smash = SmallShell::getInstance();
        JobsList::JobEntry * entry = smash.jobs_list->getLastJob();
        if (entry){
            signal(SIGALRM, SIG_DFL);
            kill(entry->pid, SIGKILL);

            signal(SIGKILL, alarmHandler);
            cout << "smash: " << entry->cmd << " timed out!" << endl;
        }
    }
}
