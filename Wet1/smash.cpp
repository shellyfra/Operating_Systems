#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include "Commands.h"
#include "signals.h"

int main(int argc, char *argv[])
{
    if (signal(SIGTSTP, ctrlZHandler) == SIG_ERR)
    {
        perror("smash error: failed to set ctrl-Z handler");
    }
    if (signal(SIGINT, tempctrlCHandler) == SIG_ERR)
    {
        perror("smash error: failed to set ctrl-C handler");
    }

    //TODO: setup sig alarm handler

    SmallShell &smash = SmallShell::getInstance();
    
    while (smash.ShouldRun())
    {
        std::cout << smash.getPromptName() << "> ";
        std::string cmd_line;
        std::getline(std::cin, cmd_line);
        if (cmd_line.empty()) continue;
        smash.executeCommand(cmd_line.c_str());
    }
    return 0;
}