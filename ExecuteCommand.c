#include "ExecuteCommand.h"

void ExecuteCommandBackground(char **args)
{
    pid_t pid;
    int status;
    //Fork a Child Process
    pid = fork();
    if (pid == 0)
    {
       if( execvp(args[0], args)==-1)
            perror("error");
    }

    else if (pid < 0)
    {
        perror("Failed");
    }

    else
    {
        return;
    }
}

void ExecuteCommandForeground(char **args)
{
    //Check If The Command is Exit
    if(strcmp(args[0],"exit")==0)
    {
        exit(0);
    }

    pid_t pid,wpid;
    int status;
    //Fork a Child Process
    pid = fork();
    if (pid == 0)
    {
       if( execvp(args[0], args)==-1)
       perror("error");
    }
    //If Failed To Fork A Child
    else if (pid < 0)
    {
        perror("Failed");
    }
    //The Parent Will Wait Until Child Process Is Terminated
    else
    {
       wait(&status);
    }
}