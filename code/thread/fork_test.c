#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char const *argv[])
{
    printf("father thread %d\n",getpid());

    pid_t pid = fork();

    if(pid<0)
    {
        printf("son thread add failture\n");
        return 1;
    }

    else if(pid==0)
    {
        printf("%dson thread is successful add it is %d recommonn\n",getpid(),getppid());
    }

    printf("%d\n",pid);
    return 0;
}