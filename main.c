#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  struct stat data;
  stat("main.c",&data);
  printf("file size: %ld\n",data.st_size);
  printf("file permissions: %o\n",data.st_mode);
  return 0;
}
