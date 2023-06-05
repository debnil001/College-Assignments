#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include<pthread.h>
sem_t semaphore1, semaphore2, semaphore3;
int turn=0;
void* p1(void* arg) {
    int i;
    for (i = 0; i < 10; i++) {
        sem_wait(&semaphore1);
        turn=0;
        printf("\nA");
        sem_post(&semaphore2);
        sleep(1);
    }
}

void* p2(void* arg) {
    int i;
    for (i = 0; i < 10; i++) {
        sem_wait(&semaphore2);
        printf("B");
        if(turn==0){
            turn++;
            sem_post(&semaphore3);
        }
        else
            sem_post(&semaphore1);
    }
}

void* p3(void* arg) {
    int i;
    for (i = 0; i < 10; i++) {
        sem_wait(&semaphore3);
        printf("C");
        if(turn==1){
            turn++;
            sem_post(&semaphore3);
        }
        else{
            sem_post(&semaphore1);
        }
    }
}
int main() {
    sem_init(&semaphore1, 0, 1);
    sem_init(&semaphore2, 0, 0);
    sem_init(&semaphore3, 0, 0);

    pthread_t tid1, tid2, tid3;

    pthread_create(&tid1, NULL, p1, NULL);
    pthread_create(&tid2, NULL, p2, NULL);
    pthread_create(&tid3, NULL, p3, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

    sem_destroy(&semaphore1);
    sem_destroy(&semaphore2);
    sem_destroy(&semaphore3);

    return 0;
}
