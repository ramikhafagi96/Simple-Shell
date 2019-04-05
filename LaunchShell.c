#include "LauncShell.h"

//SIGCHD Interrupt Handler
void handler(int sig)
{
    FILE *fp;
    fp = fopen("Children","a");
    fprintf(fp,"Child Process Is Terminated!\n");
    fclose(fp);
}

void LaunchShell(void)
{
    signal(SIGCHLD, handler);
    int BF_Flag = 0; //Background or Foreground Process
    char *line;
    char **args;
    while (1)
    {

        printf("shell> ");
        line = ReadCommand();
        //To Handler Pressing Enter With No Input
        if(*line == '\n')
            continue;

        args = ParseCommand(line,&BF_Flag);
            
        if(BF_Flag==0)
            ExecuteCommandForeground(args);

        else
            ExecuteCommandBackground(args);

        //Deallocating Memory Space
        free(line);
        free(args);
    }
}