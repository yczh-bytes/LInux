#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char const *argv[])
{
    if(argc<2)
    {
        printf("it can not go to two floor\n");
    }
    else
    {
        printf("it is %s and the number is %d it go to two floor\n",argv[1],getpid());
    }
    return 0;
}