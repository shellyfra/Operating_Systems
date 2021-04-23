#include <iostream>
#include <signal.h>
#include <unistd.h>
#include "signals.h"
#include "Commands.h"

using namespace std;

void ctrlZHandler(int sig_num) {
  
  
  if(sig_num == SIGTSTP)
  {
    
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
  
  // TODO: SHelly
  exit(1);
}

void alarmHandler(int sig_num) {
  // TODO: Add your implementation
}

