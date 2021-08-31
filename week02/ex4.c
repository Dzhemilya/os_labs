#include <stdio.h>
void swap_numbers(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int a, b;
  printf("Enter two numbers (split by space): \n");
  scanf("%d %d", &a, &b);
  printf("Before: %d %d\n", a, b);
  swap_numbers(&a, &b);
  printf("After: %d %d\n", a, b);
}
