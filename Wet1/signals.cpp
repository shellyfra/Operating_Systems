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
    pid_t pid = entry->pid;
    if (entry)
    { // If there is a running child
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
        // You can use "_logError("got ctrl-C",true);""
        cout << "smash: got ctrl-C" << endl;
        SmallShell &smash = SmallShell::getInstance();

        //  smash.jobs_list->getLastJob(); is problamatic since it might take a background/stopped job and kill it
        //  See the fix i did for cntrlZ with the foreground job member
        JobsList::JobEntry * entry = smash.jobs_list->getLastJob();

        if(entry){
            signal(SIGINT, SIG_DFL); // I don't think we need this since SIGKILL is not overriden, see my fix in cntrol Z
            kill(entry->pid, SIGKILL);
            smash.jobs_list->removeJobById(entry->job_id);
            cout << "smash: process " << entry->pid << " was killed" << endl;

            // Should delete foreground job memeber as in void ExternalCommand::execute() :
            //    delete(this->jobs->foreground_job);            
            //    this->jobs->foreground_job = nullptr;
            signal(SIGKILL, ctrlCHandler); // I don't think we need this since SIGKILL is not overriden, see my fix in cntrol Z
            // this ^ return error i think, you can't override sigkill handler
        }
    }
    signal(SIGKILL, ctrlCHandler); // I don't think we need this since SIGKILL is not overriden, see my fix in cntrol Z
    // this ^ return error i think, you can't override sigkill handler
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
