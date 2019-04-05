#include "Parser.h"
char **ParseCommand(char *line, int *ptr_BF_Flag)
{   
    //Index Variable
    int position = 0;
    //Array of Strings Where Each Position Has A Part of The Command
    char **tokens = (char **)malloc(BUFFER_SIZE * sizeof(char *));
    //A Pointer to Char To Hold Each Token
    char *token;
    //This Is Used To Eliminate New Line In The String
    //Because It Causes Issues For strtok
    char *newline = strchr(line,'\n');
    if ( newline )
        *newline = 0;

    //strtok Is Used To Break Command Into a Series of Tokens Using
    //Delimeter " "->Space
    token = strtok(line, " ");
    while (token != NULL)
    {   
        
        if(*token != '&')   
         {   
            tokens[position] = token;
            position++;
         }
        //If The Token IS '&' We Set The Flag To 1 To declare
        //The Process As Background Process
        else
        {
            *ptr_BF_Flag = 1;
        }

        token = strtok(NULL, " ");
            
    }
    tokens[position] = NULL;
    return tokens;
}

