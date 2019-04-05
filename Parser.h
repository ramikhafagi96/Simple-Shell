#ifndef PRASER_INTERFACE
#define PRASER_INTERFACE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 64
#define ARGS_LENGTH 20
char** ParseCommand(char* line,int* ptr_BF_Flag);
void privateAppendCharacter(char* string,char c);
#endif