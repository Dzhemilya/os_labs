#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 4096

int main()
{
    // define char array for user input
    char CMD[BUF_SIZE];
    // print greeting
    printf("> ");
    // scan user input cmd
    scanf("%s", CMD);
    for (;;) {
        // and run with system
        system(CMD);
        printf("> ");
        scanf("%s", CMD);
    }
    return 0;
}
