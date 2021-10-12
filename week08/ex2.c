#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  void *PTR;
  int SIZE = 1024 * 1024 * 10; // 10 MB
  for (int i = 0; i < 10; i++) // 10 times
  {
    PTR = malloc(SIZE);
    memset(PTR, 0, SIZE); // fill with zeros
    sleep(1);             // and sleep
  }
  return 0;
}

/*
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 1  0      0 7304972 155428 4411524    0    0   174   191 1069  220 14  3 83  0  0
 1  0      0 7291392 155428 4413096    0    0     0     0 6651 13445  3  2 96  0  0
 0  0      0 7285288 155436 4413308    0    0     0    88 3903 8226  2  1 97  0  0
 0  0      0 7275080 155436 4413308    0    0     0     0 3655 7815  2  1 97  0  0
 1  0      0 7268432 155476 4413236    0    0     0  4364 3684 8043  2  1 97  0  0
 0  0      0 7256924 155476 4413236    0    0     0     8 3711 8060  2  1 97  0  0
 0  0      0 7246464 155476 4413236    0    0     0     0 3776 7719  2  1 98  0  0
 0  0      0 7236792 155484 4413308    0    0     0    52 3640 8097  2  1 97  0  0
 0  0      0 7226552 155484 4413308    0    0     0     0 3703 7877  2  1 98  0  0
 0  0      0 7215368 155516 4413340    0    0     0   208 4258 8591  2  1 97  0  0
 1  0      0 7205884 155516 4413340    0    0     0     0 3818 7758  1  1 98  0  0
[1]  + 24760 done       ./ex2

In my situation I have a lot of memory -> I do not use swap
But if it will be the case -> pages will be swapped

*/
