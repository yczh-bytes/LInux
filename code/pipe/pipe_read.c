#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char const *argv[])
{
    int fd;
    char bur[100];
    fd = open("/tmp/myfio",O_RDONLY);
    if(fd==-1)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }

    int bite_size = read(fd,bur,99);
    if(bite_size>0)
    {
        bur[bite_size]='\0';
        printf("%s\n",bur);
    }
    close(fd);
    return 0;
}
