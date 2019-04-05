#include "ReadCommand.h"
char* ReadCommand(void)
{
    char *line;
    //Automatically Would Be Set By getline()
    size_t bufsize = 0;
    //Read The Input From The USer
    getline(&line, &bufsize, stdin);
    return line;  
}