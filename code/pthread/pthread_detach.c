#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_func(void* arg)
{
    printf("子线程运行\n");
 
    for(int i=0;i<3;i++)
    {
        printf("子线程开始回收 %d\n",i+1);
    }
    return NULL;
}

int main()
{
    pthread_t pid;
    void *ret = NULL;
    pthread_create(&pid,NULL,thread_func,NULL);
    printf("子线程不join detach\n");

   pthread_detach(pid);//不是终止线程，而是是线程结束后自动回收

    sleep(5);

    return 0;
}