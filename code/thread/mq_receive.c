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
    struct mq_attr attr;
    attr.mq_flags=0;
    attr.mq_maxmsg=10;//最大信息数
    attr.mq_msgsize=100;//单个信息最长数
    attr.mq_curmsgs=0;
    char *mq_name = "/my_mq";
    mqd_t mq = mq_open(mq_name,O_CREAT|O_RDONLY,0666,&attr);

    if((mqd_t)mq==-1)
    {
        perror("mq_open");
        close(mq);
        mq_unlink(mq_name);
        exit(EXIT_FAILURE);
    }

    printf("接受端接受信息中");
    pid_t pid = fork();
    {
        if(pid==-1)
        {
            perror("fork");
            close(pid);
            exit(EXIT_FAILURE);
        }
    }
    char bur[100];
    unsigned int q;

    ssize_t re = mq_receive(mq,bur,sizeof(bur),&q);
    if(re==-1)
    {
        perror("mq_recieve");
        close(mq);
        mq_unlink(mq_name);
        exit(EXIT_FAILURE);
    }

    printf("接收端接到信息%s\n",bur);

    close(mq);

    mq_unlink(mq_name);

    printf("接受端已退出\n");
    return 0;
}