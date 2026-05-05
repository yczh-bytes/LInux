#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg)
{
    printf("子线程运行\n");

    return (void*)100;//return是结束当前线程
}

int main()
{
    pthread_t pid;
    void *ret = NULL;
    pthread_create(&pid,NULL,thread_func,NULL);

    pthread_join(pid,&ret);
    printf("子线程结束，返回%ld\n",(long)ret);

    
    return 0;
}