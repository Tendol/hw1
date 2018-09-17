/*
* ls-file.c
*
* usage: ./ls-file root-directory
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

int
main(int argc, char*argv[])
{
  struct dirent *pDirent;
  DIR *root;
  char *root_name, *option;
  char file_name[256];

  if(argc != 2) {
    printf("usage: %s <root directory> <option>\n", argv[0]);
    exit(1);
  }

  root_name=argv[1];
  option = argv[2];

  int cmp=strcmp(option, "-a");
  printf("cmp = %d", cmp);

  /* open the directory */
  root=opendir(root_name);
  if(root==NULL)
  {
    perror("opendir");
    exit(1);
  }

  /* reads the files in it directory*/
  else
  {
    while((pDirent = readdir(root))!=NULL)
    {
      strncpy(file_name, pDirent->d_name, 256);
      if(file_name[0]==46)
      {
      }
      else
      {
      printf ("%s \n", pDirent->d_name);
      }
    }
  }
  /* close directory */
  closedir(root);
}
