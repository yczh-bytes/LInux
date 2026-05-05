#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* pthread_func(void* arg)
{
    //设置允许取消
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
    //设置取消类型，延迟取消
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    long long i=0;
    while(1)
    {
        i++;
        printf("子线程运行中...... %d\n",i);
        //设置手动取消点
        if(i%100000==0)
        {
        pthread_testcancel();
        }
       
    }
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
        printf("子线程取消成功\n");
    }
    return 0;
}