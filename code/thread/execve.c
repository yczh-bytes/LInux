#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char const *argv[])
{
    char *name = "banzhang";
    printf("I am %s the number is %d I am in the first floor\n",name,getpid());
    char *args[]={"/home/lz/Desktop/helloward/code/thread/erou",name,NULL};
    char *enpv[]={"PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin",NULL};
    int re = execve(args[0],args,enpv);
    if(re==-1)
    {
        printf("you is not chance go to the second floor\n");
        return 1;
    }
    return 0;

}