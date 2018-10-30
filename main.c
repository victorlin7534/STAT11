#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

int main(){
  struct stat data;
  stat("main.c",&data);

  printf("file size: %ld B\n",data.st_size);
  printf("file size: %ld KB\n",data.st_size);
  printf("file size: %ld MB\n",data.st_size);
  printf("file size: %ld GB\n",data.st_size);

  printf("file permissions: %o\n",data.st_mode);
  printf("time of last access: %s\n",ctime(&data.st_atime));

  
  struct passwd *x;
  x = getpwuid(data.st_uid);
  struct group *y;
  y = getgrgid(data.st_gid);
  char t[16]; strcpy(t,ctime(&data.st_mtime)); t[16] = '\0';
  printf("%d %s %s %ld %s main.c\n",data.st_nlink,x->pw_name,y->gr_name,data.st_size,t);
  return 0;
}
