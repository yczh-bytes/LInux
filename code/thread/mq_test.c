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
    //消息队列中的结构体
    struct mq_attr attr;
    attr.mq_flags=0;
    attr.mq_maxmsg=10;//最大信息数
    attr.mq_msgsize=100;//单个信息最长数
    attr.mq_curmsgs=0;
    char *mq_name = "/mymqueue";//消息队列一定要/为开头
    //打开消息队列
    mqd_t mq = mq_open(mq_name,O_CREAT|O_RDWR,0666,&attr);

    if((mqd_t)mq==-1)
    {
        perror("mq_open");
        close(mq);
        mq_unlink(mq_name);
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if((pid_t)pid==-1)
    {
        perror("fork");
        close(pid);
        exit(EXIT_FAILURE);
    }
    else if(pid==0)//子进程负责接受信息
    {
        char bur[100];
        unsigned int p;
        ssize_t re = mq_receive(mq,bur,sizeof(bur),&p);
        if(re==-1)
        {
            perror("mq_recieve");
            close(mq);
            return 1;
        }
        printf("子进程接收到的信息\n %s",bur);
        close(mq);
        return 0;
    }
    else//父进程负责发信息
    {
        char *message = "你好子进程，我是父进程\n";
        ssize_t se = mq_send(mq,message,strlen(message)+1,1);
        if(se==-1)
        {
            perror("mq_send");
            close(mq);
            mq_unlink(mq_name);
        }

        close(mq);
        mq_unlink(mq_name);
        printf("父进程关闭成功\n");
    }
    return 0;
}