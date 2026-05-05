#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* pthread_func(void* arg)
{
    //设置允许取消
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
    //设置取消类型，异步取消，在什么情况下都可能取消
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

    while(1)
    {
    printf("异步取消进行中\n");
    for(int i=0;i<1000;i++)
    {};

    }
    return NULL;

}

int main()
{
    pthread_t pid;
    void* ret = NULL;
    pthread_create(&pid,NULL,pthread_func,NULL);


   
    printf("发送cancel命令\n");


    pthread_cancel(pid);

    pthread_join(pid,&ret);

    if(ret==PTHREAD_CANCELED)//取消成功ret会变成PTHREAD_CANCELED
    {
        printf("子线程被异步取消\n");
    }
    return 0;
}