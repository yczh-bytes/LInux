#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char const *argv[])
{
    int s;
    printf("the old student in school\n");

    size_t pid = fork();
    if(pid<0)
    {
        perror("fork");
        return 1;
    }
    else if(pid==0)
    {
        printf("the new ping 10\n");
        char *args[] = {"sur/bin/ping","-c","10","www.baidu.com",NULL};
        char *engv[] = {NULL};
        execve(args[0],args,engv);

    }
    else 
    {
        printf("the old student %d wait the new student %d ping\n",getpid(),pid);
        waitpid(pid,&s,0);
    }
    printf("the old success wait\n");
    return 0;
}