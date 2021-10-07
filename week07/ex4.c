#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// implementation of realloc function
void *custom_realloc(void *PTR, int SIZE) {
  void *NPTR;

  // PTR is NULL -> malloc()
  if (PTR == NULL)
    return malloc(SIZE);

  // SIZE is NULL -> free()
  if (SIZE == 0) {
    free(PTR);
    return NULL;
  }

  // time to create a new chunk of memory
  NPTR = (int *)calloc(SIZE, sizeof(int));

  // copy old chunk
  memcpy(NPTR, PTR, SIZE);

  // free old PTR
  free(PTR);

  // prevent UAF
  PTR = NULL;

  return NPTR;
}

int main() {
  int N = 0;

  printf("Initial array size: ");
  scanf("%d", &N);

  // initial array size
  int *ARR = (int *)malloc(N);

  printf("[ ");

  // let it consist N numbers
  for (int i = 0; i < N; i++) {
    ARR[i] = 1337;
    if (i != N - 1)
      printf("%d ", ARR[i]);
    else
      printf("%d", ARR[i]);
  }

  int NN = 0;

  printf(" ]\nNew array size: ");
  scanf("%d", &NN);

  // custom_realloc() function -> change size of ARR
  ARR = custom_realloc(ARR, NN * sizeof(int));

  // fill with zeros
  for (int i = N; i < NN; i++)
    ARR[i] = 0;

  printf("[ ");
  for (int i = 0; i < NN; i++) {
    if (i != NN - 1)
      printf("%d ", ARR[i]);
    else
      printf("%d", ARR[i]);
  }
  printf(" ]\n");
  return 0;
}
