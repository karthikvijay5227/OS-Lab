#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
  struct stat file;
  
  char path[100];
  
  printf("Enter the location of the file to be checked:");
  scanf("%s",path);
  printf("\n");
  int a = stat(path, &file); 
  
  if(a==-1)
     printf("File doesn't exist\n");
  else
  {
     printf("ID of the given file is = %o\n", file.st_uid);
     printf("Size of the given file is = %ld bytes\n", file.st_size);
     printf("Last modified time = %s\n", ctime(&file.st_mtime));
     
     printf("User File Permissions:");
     printf( (S_ISDIR(file.st_mode))  ? "d" : "-");
     printf( (file.st_mode & S_IRUSR) ? "r" : "-");
     printf( (file.st_mode & S_IWUSR) ? "w" : "-");
     printf( (file.st_mode & S_IXUSR) ? "x" : "-");
     printf("\n"); 
     
     printf("Group File Permissions:");
     printf( (file.st_mode & S_IRGRP) ? "r" : "-");
     printf( (file.st_mode & S_IWGRP) ? "w" : "-");
     printf( (file.st_mode & S_IXGRP) ? "x" : "-");
     printf("\n");
     
     printf("Other File Permissions:");
     printf( (file.st_mode & S_IROTH) ? "r" : "-");
     printf( (file.st_mode & S_IWOTH) ? "w" : "-");
     printf( (file.st_mode & S_IXOTH) ? "x" : "-");
     printf("\n");
  } 
  
  return 0;
}
