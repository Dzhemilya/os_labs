#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define NUMBER_PROCS 4
#define NUMBER_RES 3

enum STATE { BLOCKED = 0, EXECUTED = 1 };

void PARSE(FILE *fd, int ALLOC[NUMBER_PROCS][NUMBER_RES],
           int NEED[NUMBER_PROCS][NUMBER_RES], int AVAILABLE[NUMBER_RES]) {
  for (int i = 0; i < NUMBER_RES; i++)
    fscanf(fd, "%i", &AVAILABLE[i]);

  for (int i = 0; i < NUMBER_PROCS; i++)
    for (int j = 0; j < NUMBER_RES; j++)
      fscanf(fd, "%i", &ALLOC[i][j]);

  for (int i = 0; i < NUMBER_PROCS; i++)
    for (int j = 0; j < NUMBER_RES; j++)
      fscanf(fd, "%i", &NEED[i][j]);
}

void BANKER(int ALLOC[NUMBER_PROCS][NUMBER_RES],
            int NEED[NUMBER_PROCS][NUMBER_RES], int AVAILABLE[NUMBER_RES],
            enum STATE PROC[NUMBER_PROCS]) {
  for (int k = 0; k < NUMBER_PROCS; k++)
    for (int i = 0; i < NUMBER_PROCS; i++)
      if (PROC[i] != EXECUTED) {
        int PERM = 1;
        for (int j = 0; j < NUMBER_RES; j++)
          if (NEED[i][j] > AVAILABLE[j]) {
            PERM = 0;
            break;
          }

        if (PERM) {
          for (int j = 0; j < NUMBER_RES; j++)
            AVAILABLE[j] += ALLOC[i][j];
          PROC[i] = EXECUTED;
        }
      }
}

void DISPLAY(enum STATE PROC[NUMBER_PROCS]) {
  char FLAG = 1;
  for (int i = 0; i < NUMBER_PROCS; i++)
    if (PROC[i] == BLOCKED) {
      FLAG = 0;
      break;
    }

  if (FLAG == 1) {
    printf("No deadlock!\n");
  } else {
    printf("Deadlock occurred with:\n ");
    for (int i = 0; i < NUMBER_PROCS; i++)
      if (PROC[i] == BLOCKED)
        printf("P%d, ", i);
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  int ALLOC[NUMBER_PROCS][NUMBER_RES];
  int NEED[NUMBER_PROCS][NUMBER_RES];
  int AVAILABLE[NUMBER_RES];
  enum STATE PROC[NUMBER_PROCS] = {0};

  FILE *FD = fopen(argv[1], "r");

  PARSE(FD, ALLOC, NEED, AVAILABLE);
  BANKER(ALLOC, NEED, AVAILABLE, PROC);
  DISPLAY(PROC);

  fclose(FD);
  return 0;
}
