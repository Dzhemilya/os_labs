#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main()
{
    // create array for store input string
    char INPUT[BUF_SIZE];
    // infinite loop
    for (;;) {
        // get user input
        fgets(INPUT, sizeof(INPUT), stdin);
        // time to initiailize arguments array
        char* ARGUMENTS[BUF_SIZE];
        *ARGUMENTS = (char*)malloc(BUF_SIZE);
        int _POS = 0, POS = 0, ARGUMENT = 0;
        // while we do  not reach end of line
        while (INPUT[_POS] != '\n') {
            // if we get not space delimeter (one char of argument)
            if (INPUT[_POS] != ' ') {
                ARGUMENTS[ARGUMENT][POS] = INPUT[_POS];
                POS++;
            }
            // but if we get space delimeter -> we will have next argument
            else if (INPUT[_POS] == ' ') {
                ARGUMENT++;
                POS = 0;
                ARGUMENTS[ARGUMENT] = (char*)malloc(BUF_SIZE);
            }
            _POS++;
        }
        // time to create new process to run program in it
        int PROCESS = fork();
        // substitute newly created process image with new binary and pass argument list
        if (!PROCESS) {
            execvp(ARGUMENTS[0], ARGUMENTS);
        }
    }
    return 0;
}
