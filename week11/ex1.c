#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main() {
  int RANDOM = open("/dev/random", O_RDONLY);
  FILE *FP;
  FP = fopen("ex1.txt", "w");
  char DATA[20];
  read(RANDOM, DATA, sizeof DATA);
  fprintf(FP, "%s", DATA);
  return 0;
}
