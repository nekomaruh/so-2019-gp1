#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_FILOS 5

 pthread_mutex_t forks[NUM_FILOS];

void actions(){sleep(1+rand()%5);}

void *life(void *ptID){
    long tid = (long) ptID;
    srand(time(NULL)+tid);
    if(NUM_FILOS<2){
        printf("No puedo comer tan poquito %ld\n ",tid);
        exit(-1);
    }
    while (1) {
        // Pensar
        printf("Voy a pensar un rato %ld\n ",tid);
        actions();
        printf("Tengo hambre %ld\n ",tid);
        if(tid%2 == 0){
            pthread_mutex_lock(&forks[tid]);
            printf("Tengo más hambre, me comeré el plato de mi amigo la derecha %ld\n ",tid);
            pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);
            printf("Tengo tanta hambre que me robaré y me comeré el plato de mi amigo a la izquierda %ld\n ",tid);
            // Comer
            printf("Tengo hambre %ld\n ",tid);
            actions();
            printf("Regresaré los tenedores a su sitio %ld\n ",tid);
            pthread_mutex_unlock(&forks[tid]);
            pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);
        }else{
            pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);
            printf("Tengo tanta hambre que me robaré y me comeré el plato de mi amigo a la izquierda %ld\n ",tid);
            pthread_mutex_lock(&forks[tid]);
            printf("Tengo más hambre, me comeré el plato de mi amigo la derecha %ld\n ",tid);
            // Comer
            printf("Tengo hambre %ld\n ",tid);
            actions();
            printf("Regresaré los tenedores a su sitio %ld\n ",tid);
            pthread_mutex_unlock(&forks[tid]);
            pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);
        }
    }
}

int main (int argc, char *argv[]){
    pthread_t threads[NUM_FILOS];
    int rc;
    long t;
    for(t=0; t<NUM_FILOS; t++){
       printf("In main: creating thread %ld\n", t);
       rc = pthread_create(&threads[t], NULL, life, (void *)t);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }
    /* Last thing that main() should do */
    pthread_exit(NULL);
 }