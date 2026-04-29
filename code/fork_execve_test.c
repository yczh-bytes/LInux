#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc,char const *argv[])
{
    printf("The old student the number is %d is study in old place\n",getpid());

    size_t fo = fork();
    if(fo==-1)
    {
        printf("Faulture invite the new student\n");
        return 1;
    }
    else if(fo==0)
    {
        char *name = "erou";
        char *args[]={"/home/lz/Desktop/helloward/code/thread/erou",name,NULL};
        char *engv[]={NULL};
        int t = execve(args[0],args,engv);

        if(t==-1)
        {
            printf("The new student failture go to the second floor\n");
            return 1;
        }
        
    }

    else
    printf("The old student %d still in old place\n",getpid());
    return 0;
}