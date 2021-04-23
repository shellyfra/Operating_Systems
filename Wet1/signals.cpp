#include <iostream>
#include <signal.h>
#include <unistd.h>
#include "signals.h"
#include "Commands.h"

using namespace std;

void ctrlZHandler(int sig_num) {
  if(sig_num == SIGTSTP)
  {
    cout << "smash: got ctrl-Z" << endl;
    SmallShell &smash = SmallShell::getInstance();
    JobsList::JobEntry * entry = smash.jobs_list->getLastJob();
    
    if(entry)
    {
      
    signal(SIGTSTP, SIG_DFL); 
    entry->job_stopped=true;
    kill(entry->pid, SIGTSTP);
    
    signal(SIGTSTP, ctrlZHandler); 
    }
  }
}

void ctrlCHandler(int sig_num) {
    // possible only to external commands - SHOULD CHANGE ??
    if(sig_num == SIGINT)
    {
        cout << "smash: got ctrl-C" << endl;
        SmallShell &smash = SmallShell::getInstance();
        JobsList::JobEntry * entry = smash.jobs_list->getLastJob();

        if(entry){
            //signal(SIGINT, SIG_DFL);
            kill(entry->pid, SIGKILL);
            smash.jobs_list->removeJobById(entry->job_id);
            cout << "smash: process " << entry->pid << " was killed" << endl;
            signal(SIGKILL, ctrlCHandler);
        }
    }
    //signal(SIGKILL, ctrlCHandler);
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

