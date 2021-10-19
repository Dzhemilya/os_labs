#include <stdio.h>
#include <stdlib.h>
int main() {
  printf("Enter number of pages: ");
  int page_number;
  scanf("%d", &page_number);
  FILE *file = fopen("input.txt", "r");
  long counter[page_number];
  int page_table[page_number];
  for (int i = 0; i < page_number; i++) {
    page_table[i] = -1;
    counter[i] = 0;
  }
  int miss = 0;
  int hit = 0;
  for (int j = 0; j < 1000; j++) {
    int access;
    fscanf(file, "%d", &access);
    int flag = 0;
    int id = -1;
    for (int i = 0; i < page_number; i++) {
      if (page_table[i] == access) {
        hit++;
        flag = 1;
        id = i;
        break;
      }
    }
    if (!flag) {
      miss++;
      for (int i = 0; i < page_number; i++) {
        if (page_table[i] == -1) {
          id = i;
          break;
        }
      }
      if (id == -1) {
        int min = counter[0];
        id = 0;
        for (int i = 1; i < page_number; i++) {
          if (counter[i] < min) {
            min = counter[i];
            id = i;
          }
        }
      }
      page_table[id] = access;
    }
    for (int i = 0; i < page_number; i++) {
      counter[i] = counter[i] >> 1;
    }
    counter[id] = counter[id] | 128;
  }
  printf("Hits/Miss ratio: %f\n", (float)hit / (float)miss);
  fclose(file);
  return 0;
}
