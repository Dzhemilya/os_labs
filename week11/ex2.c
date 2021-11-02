#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
int main(int argc, char **argv) {
  int offset;
  char* mode, DATA;
  if (strcmp(argv[1], "-a") == 0) {
    mode = "a+";
    offset = 2;
  } else {
    mode = "w+";
    offset = 1;
  }
  FILE **FILES = malloc((argc - offset + 1) * sizeof(FILE *));
  for (int i = offset; i < argc; i++) {
    FILES[i - offset] = fopen(argv[i], mode);
  }
  FILES[argc - offset] = stdout;
  while (fread(&DATA, 1, 1, stdin)) {
    for (int i = 0; i < argc - offset; i++) {
      fwrite(&DATA, 1, 1, FILES[i]);
    }
  }
  return 0;
}
