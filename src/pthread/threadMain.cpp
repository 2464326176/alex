#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "saleTicket.h"


struct mt {
    int num;
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexattr;
};

const int THREAD_NUMM = 8;

struct mt {
    int num;
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexattr;
};

int main()
{
    int i;
    struct mt *mm;
    pid_t pid;

    mm = mmap(NULL, sizeof(*mm), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANON, -1, 0);
    memset(mm, 0, sizeof(*mm));

    pthread_mutexattr_init(&mm->mutexattr);                                  //初始化mutex属性对象
    pthread_mutexattr_setpshared(&mm->mutexattr, PTHREAD_PROCESS_SHARED);    //修改属性为进程间共享
    pthread_mutex_init(&mm->mutex, &mm->mutexattr);                          //初始化一把mutex琐


    TICKET ticket;
    ticket.nCount = 100;
    strcpy(ticket.strTicketName, "北京-->赣州");
    THD_DATA threadSale[THREAD_NUMM];
    pthread_t tid[5];
    long *ret[5];


    printf("父进程-----pthread_id = %lu\n", pthread_self());
    for (int i = 0; i < THREAD_NUMM; i++){

        threadSale[i].pTicket = &ticket;
        std::string strThreadName = convertToString(i);
        strThreadName = "窗口" + strThreadName;
        strcpy(threadSale[i].strThreadName, strThreadName.c_str());

        pthread_mutex_lock(&mm->mutex);
        pthread_create(&tid[i], NULL, SaleTicket, (void *)threadSale[i]);
        cout << threadSale[i].strThreadName << "开始出售 " << threadSale[i].pTicket->strTicketName << " 的票..." << endl;
        (mm->num)++;
        pthread_mutex_unlock(&mm->mutex);

    }


    for (i = 0; i < 5; i++) {
        pthread_join(tid[i], (void **)&ret[i]);
        printf("-------%d 's ret = %d\n", i, (long)ret[i]);
    }

    printf("I'm main pthread tid = %lu\t var = %d\n", pthread_self(), var);


    pthread_mutexattr_destroy(&mm->mutexattr);          //销毁mutex属性对象
    pthread_mutex_destroy(&mm->mutex);                  //销毁mutex
    munmap(mm,sizeof(*mm));                             //释放映射区

    return 0;
}