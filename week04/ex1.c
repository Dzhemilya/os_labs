#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int n)
{
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("Hello from child [%d]", pid);
        printf("\n");
    }
    else if (pid <= -1) {
        return 1;
    }
    else
        printf("Hello from parent [%d]", pid);
    printf("\n");
    return 0;
}

