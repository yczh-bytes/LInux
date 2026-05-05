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
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t pid;
    void *ret = NULL;
    pthread_create(&pid,NULL,thread_func,NULL);
    printf("开始join,开始回收子线程\n");

    pthread_join(pid,&ret);//线程创建出来是joinable，不能够自动回收，需要join一下

    printf("子线程回收结束\n");

    return 0;
}