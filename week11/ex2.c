#include <dirent.h>
#include <stdio.h>

int main(void) {
  DIR *CURRENT_DIR;
  struct dirent *dir;
  CURRENT_DIR = opendir("/");
  while ((dir = readdir(CURRENT_DIR)) != NULL) {
    printf("%s\n", dir->d_name);
  }
  closedir(CURRENT_DIR);
  return (0);
}
