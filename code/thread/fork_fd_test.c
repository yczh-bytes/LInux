#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd = open("io.txt",O_CREAT|O_APPEND|O_WRONLY,0644);
    if(fd==-1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char bur[1024];
    pid_t pid = fork();
    if(pid<0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if(pid==0)
    {
        strcpy(bur,"This is son thread add!\n");
    }
    else
    {
        sleep(1);
        strcpy(bur,"This is father thread add\n");
    }

    size_t w = write(fd,bur,strlen(bur));
    
    if(w==-1)
    {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }
    if(pid==0)
    {
        printf("son thread success\n");
    }
    else 
    {
        printf("father thread success\n");
    }
    close(fd);
    return 0;
}