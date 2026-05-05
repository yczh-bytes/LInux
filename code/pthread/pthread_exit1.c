#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_func(void* arg)
{
    printf("子线程开始运行\n");

 for(int i=0;i<5;i++)
 {
    printf("子线程正在运行 %lld\n",i);
 }
    
    return NULL;
}

int main()
{
    pthread_t pid;
    void *ret = NULL;
    pthread_create(&pid,NULL,thread_func,NULL);

    printf("主线程调用exit\n");
    pthread_exit(NULL);//主线程调用会立马结束主线程但是子线程不受影响运行结束


    //return 0;
}