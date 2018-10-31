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
  int i,z;
  char read[100], perm[11];

  sprintf(read,"file size: %0.f B\n",data.st_size/1.0); printf(read);
  sprintf(read,"file size: %f KB\n",data.st_size/1000.0); printf(read);
  sprintf(read,"file size: %f MB\n",data.st_size/1000000.0); printf(read);
  sprintf(read,"file size: %f GB\n",data.st_size/1000000000.0); printf(read);

  printf("file permissions: %o\n",data.st_mode);
  printf("time of last access: %s\n",ctime(&data.st_atime));

  int mode = data.st_mode;
  for(i=0,z=1;i<9;i++,z++,mode=mode>>1){
  	if(mode & 1){
  		if(z==1) strcat(perm,"x");
  		if(z==2) strcat(perm,"w");
  		if(z==3) strcat(perm,"r");
  	}
  	else strcat(perm,"-");
  	if(z==3) z = 1;
  }
  strcat(perm,"d");
  perm[10] = '\0';
  for(i=10;i>=0;i--)
  	printf("%c",perm[i]);

  struct passwd *x; x = getpwuid(data.st_uid);
  struct group *y; y = getgrgid(data.st_gid);
  char t[16]; strcpy(t,ctime(&data.st_mtime)); t[16] = '\0';
  printf(" %ld %s %s %ld %s main.c\n",data.st_nlink,x->pw_name,y->gr_name,data.st_size,t);

  return 0;
}
