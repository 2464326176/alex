#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

long var = 100;

void *tfn(void *arg)
{
    long i;

    i = (long)arg;
    
    usleep(i);

    printf("I'm %dth pthread, pthread_id = %lu\n var = %d\n", i+1, pthread_self(), var);

    return NULL;
}

int main()
{
    pthread_t tid[5];
    long i;
    long *ret[5];  

    for (i = 0; i < 5; i++){

        pthread_create(&tid[i], NULL, tfn, (void *)i);
        printf("I'm %dth pthread, pthread_id = %lu\n var = %d\n", i+1, pthread_self(), 10 - i);


    }



    for (i = 0; i < 5; i++) {
        pthread_join(tid[i], (void **)&ret[i]);
        printf("-------%d 's ret = %d\n", i, (long)ret[i]);
    }
    return 0;
}
