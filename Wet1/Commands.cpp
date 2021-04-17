#include <unistd.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <sys/wait.h>
#include <iomanip>
#include <climits>
#include "Commands.h"

using namespace std;

#if 0
#define FUNC_ENTRY() \
  cout << __PRETTY_FUNCTION__ << " --> " << endl;

#define FUNC_EXIT() \
  cout << __PRETTY_FUNCTION__ << " <-- " << endl;
#else
#define FUNC_ENTRY()
#define FUNC_EXIT()
#endif

string _ltrim(const std::string &s)
{
  size_t start = s.find_first_not_of(WHITESPACE);
  return (start == std::string::npos) ? "" : s.substr(start);
}

string _rtrim(const std::string &s)
{
  size_t end = s.find_last_not_of(WHITESPACE);
  return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

string _trim(const std::string &s)
{
  return _rtrim(_ltrim(s));
}

void log_error(const char *text)
{
  string text_str(text);
  string message = "smash error: " + text_str;
  perror(message.c_str());
}
int _parseCommandLine(const char *cmd_line, char **args)
{
  FUNC_ENTRY()
  int i = 0;
  
  std::istringstream iss(_trim(string(cmd_line)).c_str());
  for (std::string s; iss >> s;)
  {
    args[i] = (char *)malloc(s.length() + 1);
    memset(args[i], 0, s.length() + 1); // Make 's.length() + 1' bytes of zero
    strcpy(args[i], s.c_str());         // Copy the arguement
    args[++i] = NULL;
  }
  return i;

  FUNC_EXIT()
}

bool _isBackgroundComamnd(const char *cmd_line)
{
  const string str(cmd_line);
  return str[str.find_last_not_of(WHITESPACE)] == '&';
}

void _removeBackgroundSign(char *cmd_line)
{
  const string str(cmd_line);
  // find last character other than spaces
  unsigned int idx = str.find_last_not_of(WHITESPACE);
  // if all characters are spaces then return
  if (idx == string::npos)
  {
    return;
  }
  // if the command line does not end with & then return
  if (cmd_line[idx] != '&')
  {
    return;
  }
  // replace the & (background sign) with space and then remove all tailing spaces.
  cmd_line[idx] = ' ';
  // truncate the command line string up to the last non-space character
  cmd_line[str.find_last_not_of(WHITESPACE, idx) + 1] = 0;
}

// TODO: Add your implementation for classes in Commands.h

SmallShell::SmallShell()
{
  this->last_wd = nullptr;
}

SmallShell::~SmallShell()
{
  // TODO: add your implementation
  free(last_wd);
}

BuiltInCommand::BuiltInCommand(const char *cmd_line) : Command(cmd_line)
{
  this->args = (char **)malloc(sizeof(char *) * COMMAND_MAX_ARGS);
  this->argc = _parseCommandLine(cmd_line, this->args);
}

BuiltInCommand::~BuiltInCommand()
{
  for (int i = 0; i < argc; i++)
  {
    free(args[i]);
  }
  free(args);
}
/**
* Creates and returns a pointer to Command class which matches the given command line (cmd_line)
*/
std::string SmallShell::getPromptName() {
    return prompt_name;
}
void SmallShell::changePrompt(const char *cmd_line) {
    char ** args = (char **)malloc(sizeof(char *) * COMMAND_MAX_ARGS);
    int argc = _parseCommandLine(cmd_line, args);
    if (argc < 1) {
        log_error("chprompt: too few arguments"); // CHECK with staff!
    }
    else if (argc == 1) {
        prompt_name = DEFALT_PROMPT;
    }
    else {
        prompt_name = args[1];
    }
}
Command *SmallShell::CreateCommand(const char *cmd_line)
{
  // For example:

  string cmd_s = _trim(string(cmd_line));
  string firstWord = cmd_s.substr(0, cmd_s.find_first_of(" \n"));

  if (firstWord.compare("pwd") == 0)
  {
    return new GetCurrDirCommand(cmd_line);
  }
  else if (firstWord.compare(SHOW_PID_COMMAND_STR) == 0)
  {
    return new ShowPidCommand(cmd_line);
  }
  else if (firstWord.compare(CHANGE_DIRECTORY_COMMAND_STR) == 0)
  {
    return new ChangeDirCommand(cmd_line, &last_wd);
  }
  else if (firstWord.compare(CHANGE_PROMPT_COMMAND_STR) == 0)
  {
      changePrompt(cmd_line);
  }
  else
  {
    //return new ExternalCommand(cmd_line);
  }

  return nullptr;
}

void SmallShell::executeCommand(const char *cmd_line)
{
  // TODO: Add your implementation here
  // for example:
  Command *cmd = CreateCommand(cmd_line);
  if (cmd)
  {
    cmd->execute();
  }

  // Please note that you must fork smash process for some commands (e.g., external commands....)
}
void ShowPidCommand::execute()
{
  cout << "smash pid is " << getpid() << endl;
}

void ChangeDirCommand::execute()
{
  if (argc < 2)
  {
    log_error("cd: too few arguments"); // CHECK with staff!
    return;
  }
  else if (this->argc > 2)
  {
    log_error("cd: too many arguments");
    return;
  }
  const char *first_arg = args[1];
  const char *path = (strlen(first_arg) == 1 && *(first_arg) == '-') ? *plastPwd : first_arg;

  if(path ==nullptr)
  {
    log_error("cd: OLDPWD not set");
    
  }
  else if (chdir(path))
  { // Error
    log_error("chdir failed");
    
  }
  else
  { // cd successfull
    if (! *plastPwd)
    {
      (*plastPwd) = (char *)malloc(COMMAND_ARGS_MAX_LENGTH + 1);
    }
    strcpy(*plastPwd, path);
  }

}

void GetCurrDirCommand::execute() {
    if (argc < 1) {
        log_error("cd: too few arguments"); // CHECK with staff!
        return;
    }

    char buff[PATH_MAX];
    char * val = getcwd( buff, PATH_MAX );
    if (val == nullptr) {
        log_error("pwd: getcwd failed"); // CHECK with staff!
        return;
    }
    std::string cwd( buff );
    cout << cwd << endl;
    return;
}
