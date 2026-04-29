#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char const *argv[])
{
    pid_t cpid;
    int ppie[2];
    if(argc!=2)
    {
        fprintf(stderr,"%s please input message",argv[0]);
        exit(EXIT_FAILURE);
    }
    if(pipe(ppie)==-1)
    {
        perror("pipe creat is failure");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
    if(cpid<0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    else if(cpid==0)
    {
        close(ppie[1]);
        printf("the new student receive\n");
        char buf;
        while(read(ppie[0],&buf,1)>0)
        {
            write(STDOUT_FILENO,&buf,1);
        }
        write(STDOUT_FILENO,"\n",1);
        _exit(EXIT_FAILURE);
    }
    else
    {
        close(ppie[0]);

        printf("the old student %d set message to new student\n",getpid());
        write(ppie[1],argv[1],strlen(argv[1]));
        close(ppie[1]);
        waitpid(cpid,NULL,0);
        exit(EXIT_FAILURE);

    }
    return 0;
}