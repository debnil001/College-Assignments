
#include <stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<time.h>
#define turn 10
// #define items 5
// #define size 10
sem_t wrt;
pthread_mutex_t mutex;
int cnt=1;
int readerCount=0;

void* wrtr(void* arg){
    for(int i=0;i<turn;i++){
        sem_wait(&wrt);
        cnt*=2;
        printf("Writer modified counter to %d\n",cnt);
        sem_post(&wrt);
    }
}
void* rdr(void* arg){
    for(int i=0;i<turn;i++){
        pthread_mutex_lock(&mutex);
        readerCount++;
        if(readerCount==1){
            sem_wait(&wrt);
        }
        pthread_mutex_unlock(&mutex);
        //reading
        printf("Reader read counter as %d\n",cnt);
        pthread_mutex_lock(&mutex);
        readerCount--;
        if(readerCount==0){
            sem_post(&wrt);
        }
        pthread_mutex_unlock(&mutex);
            
    }
}
int main(){
    pthread_t reader,writer;
    pthread_mutex_init(&mutex,NULL);
    sem_init(&wrt,0,1);
    pthread_create(&reader,NULL,rdr,NULL);
    pthread_create(&writer,NULL,wrtr,NULL);
    pthread_join(reader,NULL);
    pthread_join(writer,NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}



#include <stdio.h>
#include <pthread.h>

#define MAX_READERS 3

int readers_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t read_condition = PTHREAD_COND_INITIALIZER;

void *reader(void *arg) {
    // Entry section
    pthread_mutex_lock(&mutex);

    // Wait if maximum number of readers are already in the CS
    while (readers_count >= MAX_READERS) {
        pthread_cond_wait(&read_condition, &mutex);
    }

    // Increment readers count
    readers_count++;

    // Release the lock
    pthread_mutex_unlock(&mutex);

    // Critical section (reading)
    printf("Reader %ld in critical section\n", (long)arg);

    // Exit section
    pthread_mutex_lock(&mutex);

    // Decrement readers count
    readers_count--;

    // Signal the waiting readers that a slot is available
    pthread_cond_broadcast(&read_condition);

    // Release the lock
    pthread_mutex_unlock(&mutex);

    // Rest of the code (after critical section)
    return NULL;
}

void *writer(void *arg) {
    // Writer code
    // ...
    return NULL;
}

int main() {
    pthread_t reader_threads[5];
    pthread_t writer_thread;

    // Create reader threads
    for (int i = 0; i < 5; i++) {
        pthread_create(&reader_threads[i], NULL, reader, (void *)(long)i);
    }

    // Create writer thread
    pthread_create(&writer_thread, NULL, writer, NULL);

    // Join reader threads
    for (int i = 0; i < 5; i++) {
        pthread_join(reader_threads[i], NULL);
    }

    // Join writer thread
    pthread_join(writer_thread, NULL);

    return 0;
}








#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_READERS 3

int shared_data = 0;
int readers_count = 0;
sem_t mutex;
sem_t readers_sem;

void *reader(void *arg)
{
    int reader_id = *(int *)arg;
    while (1) {
        sem_wait(&readers_sem);  // Wait until there's room for the reader
        sem_wait(&mutex);        // Acquire the mutex to update readers_count
        readers_count++;
        if (readers_count == 1) {
            // If this is the first reader, wait for any writers to finish
            sem_wait(&readers_sem);
        }
        sem_post(&mutex);        // Release the mutex

        // Reading the shared data
        printf("Reader %d reads: %d\n", reader_id, shared_data);

        sem_wait(&mutex);        // Acquire the mutex to update readers_count
        readers_count--;
        if (readers_count == 0) {
            // If this is the last reader, allow writers to proceed
            sem_post(&readers_sem);
        }
        sem_post(&mutex);        // Release the mutex
    }
}

void *writer(void *arg)
{
    int writer_id = *(int *)arg;
    while (1) {
        sem_wait(&readers_sem);  // Wait until there's room for the writer

        // Writing to the shared data
        shared_data++;
        printf("Writer %d writes: %d\n", writer_id, shared_data);

        sem_post(&readers_sem);  // Release the readers semaphore
    }
}

int main()
{
    pthread_t readers[MAX_READERS];
    pthread_t writers;
    int reader_ids[MAX_READERS];
    int writer_id = 1;

    sem_init(&mutex, 0, 1);
    sem_init(&readers_sem, 0, MAX_READERS);

    // Create reader threads
    for (int i = 0; i < MAX_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer thread
    pthread_create(&writers, NULL, writer, &writer_id);

    // Wait for threads to finish (this is an infinite loop)
    for (int i = 0; i < MAX_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    pthread_join(writers, NULL);

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&readers_sem);

    return 0;
}

