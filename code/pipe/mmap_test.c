#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <fcntl.h>

int main()
{
    
    char *shm_name = "/hello";
    int fd;
    //创建
    fd = shm_open(shm_name,O_CREAT|O_RDWR,0666);
    if(fd==-1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }
//开辟共享内存空间
    ftruncate(fd,1024);
    char *shm_add;
    //内存映射
    shm_add = mmap(NULL,1024,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(shm_add == MAP_FAILED)
    {
        perror("mmap");
          shm_unlink(shm_name);
        exit(EXIT_FAILURE);
    }
    
    close(fd);

    pid_t pid = fork();
    if(pid ==-1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if(pid ==0)
    {
        printf("the new student %d write message\n",getpid());
        strcpy(shm_add,"hello the old student");
    }
    else
    {
        sleep(1);
        printf("the old student %d recive the new student %d message %s",getpid(),pid,shm_add);
    }
    //销毁
    munmap(shm_add,1024);
    shm_unlink(shm_name);


    
    return 0;
}