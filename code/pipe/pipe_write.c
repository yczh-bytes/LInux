#include <stdio.h>
#include <string.h>
#include <error.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char const *argv[])
{
    int fd;
    char *path_myfio="/tmp/myfio";
    char *message = "hello writer";
    if(mkfifo(path_myfio,0644)!=0)
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }
    fd = open(path_myfio,O_WRONLY);
    if(fd==-1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(fd,message,strlen(message));
    printf("%s\n",message);
    close(fd);
    return 0;
}