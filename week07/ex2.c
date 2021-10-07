#include <stdio.h>
#include <stdlib.h>

int main() {
  int N = 0;

  // get user input
  printf("Enter number of integers: ");
  scanf("%d", &N);

  // allocate array of N integers
  int *ARR = (int *)malloc(N);

  for (int i = 0; i < N; i++) {
    ARR[i] = i;
    printf("Value: %d\n", ARR[i]);
  }

  // time to deallocate memory
  free(ARR);
  // and prevent UAF
  ARR = NULL;

  return 0;
}
