#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_func(void* arg)
{
    printf("子线程调用exit\n");

    exit(0);//调用exit整个进程都会结束
    
    return NULL;
}

int main()
{
    pthread_t pid;
    void *ret = NULL;
    pthread_create(&pid,NULL,thread_func,NULL);

  while(1)
  {
    printf("主线程还在运行\n");
    sleep(1);
  }

  printf("整个线程终止\n");
    return 0;
}