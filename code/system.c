#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
    int fd = open("A.txt",O_WRONLY|O_CREAT|O_TRUNC,0064);
    if(fd==-1)
    {
        
        return 1;
    }
    else
    {
        const char* msg = "hello linux\n";
        write(fd,msg,strlen(msg));

    }
    close(fd);
    int fd1 = open("A.txt",O_RDONLY);
    if(fd1==-1)
    {
        perror("read");
        return 1;
    }
    char s[100];
    size_t n = read(fd1,s,strlen(s)-1);
    if(n==-1)
    {
        perror("size_t");
        return 1;
    }

    s[n]='\0';
    printf("%s",s);
    close(fd1);
    return 0;
}