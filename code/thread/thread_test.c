#include <pthread.h>
#include <stdio.h>

void *task(void *arg)
{
    printf("子线程创建\n");
    return NULL;
    //线程终止
    pthread_exit(NULL);

    printf("这句话不会被执行\n");
}

int main()
{
    pthread_t pdt;

    int ret = pthread_create(&pdt,NULL,task,NULL);

    if(ret!=0)
    {
        printf("线程创建失败\n");
        return 1;
    }

    pthread_join(pdt,NULL);
    return 0;
}