#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void FINDSAME(ino_t INODE, char *NAME)
{
  struct stat STATBUF;
  DIR *DIRP;
  struct dirent *DP;

  DIRP = opendir("."); // open current dir

  while ((DP = readdir(DIRP)) != NULL) // check files
  {
    if (lstat(DP->d_name, &STATBUF) == -1) // get structure of file
    {
      puts("Permission denied!");
      continue;
    }
    if (STATBUF.st_mode & S_IFMT != S_IFDIR) // if directory -> skip
      continue;

    if ((STATBUF.st_ino == INODE) && (strcmp(DP->d_name, NAME)))
      printf("\t%s", DP->d_name);
  }
  printf(" ]\n");
  closedir(DIRP); // close current dir
}

void FINDALL()
{
  DIR *DIRP;
  struct dirent *DP;
  struct stat STATBUF;

  DIRP = opendir("./tmp/"); // open tmp/

  chdir("./tmp/"); // switch to tmp/
  while ((DP = readdir(DIRP)) != NULL)
  {
    if (lstat(DP->d_name, &STATBUF) == -1)
    {
      puts("Permissiond denied!");
      continue;
    }
    if (STATBUF.st_mode & S_IFMT != S_IFDIR) // if directory -> skip
      continue;

    if (STATBUF.st_nlink > 1) // if hard link count > 1
    {
      printf("[ %s: ", DP->d_name); // print filename
      FINDSAME(STATBUF.st_ino, DP->d_name); // time to find files with the same inode
    }
  }
  closedir(DIRP); // close tmp/ dir
}

int main()
{
  FINDALL();
  return 0;
}
