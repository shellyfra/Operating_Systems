#include <iostream>
#include <signal.h>
#include <unistd.h>
#include "signals.h"
#include "Commands.h"

using namespace std;

void ctrlZHandler(int sig_num) {
	DO_SYS(kill(getpid(),SIGTSTP));
 // DO_SYS(signal(SIGTSTP, ctrlZHandler));
}

void ctrlCHandler(int sig_num) {
  
  // TODO: SHelly
  exit(1);
}

void alarmHandler(int sig_num) {
  // TODO: Add your implementation
}

