#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
   
    char *mq_name = "/my_mq";
    mqd_t mq = mq_open(mq_name,O_WRONLY);

     if((mqd_t)mq==-1)
    {
        perror("mq_open");
        close(mq);
        mq_unlink(mq_name);
        exit(EXIT_FAILURE);
    }

    char message[100];

    fgets(message,sizeof(message),stdin);

    message[strcspn(message, "\n")] = '\0';

    if(mq_send(mq,message,strlen(message)+1,1)==-1)
    {
        perror("mq_open");
        close(mq);
      exit(EXIT_FAILURE);
    }

        printf("发送端：消息发送成功\n");

        close(mq);
    return 0;
}