#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int n)
{
    pid_t pid;
    for (int i =0; i<3;i++)
            pid = fork();
    sleep(5);
    return 0;
}
