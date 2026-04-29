#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *task(void *arg)
{
    printf("子线程创建\n");
    int *result = malloc(sizeof(int));
    *result = 100;
    return result;//线程函数可以返回一个指针
 
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

    void *ref=NULL;
    printf("主线程正在等待子线程\n");
    
    pthread_join(pdt,&ref);//join可以接受这个指针
    printf("接收的子线程数据是%d\n",*(int*)ref);

    printf("子线程运行完毕，主线程不再等待\n");
    return 0;
}