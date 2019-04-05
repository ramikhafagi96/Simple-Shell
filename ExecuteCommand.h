#ifndef EXECUTECOMMAND
#define EXECUTECOMMAND
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
void ExecuteCommandHandler(char **args);
void ExecuteCommandBackground(char **args);
void ExecuteCommandForeground(char **args);
#endif