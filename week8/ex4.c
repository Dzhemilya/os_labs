#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
  void *PTR;
  struct rusage USE;
  int SIZE = 1024 * 1024 * 10; // 10 MB
  for (int i = 0; i < 10; i++) // 10 times
  {
    PTR = malloc(SIZE);
    memset(PTR, 0, SIZE);                         // fill with zeros
    getrusage(RUSAGE_SELF, &USE);                 // get current memory usage
    printf("Memory usage: %ld\n", USE.ru_maxrss); // print
    sleep(1);                                     // and sleep
  }
  return 0;
}
