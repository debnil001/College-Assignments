#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

// Define a Counter Variable.
int c = 0; 

sem_t s1, s2, s3;
int turn = 1;
//A B C C A B 
//A B C C A B..

void* A() {
	while(1) {
		sem_wait(&s1);
		//sleep(1);
		printf("A");
		sem_post(&s2);
	}
}

void* B() {
	while(1){
		if(c==10)
		{
			exit(0);
		}
		sem_wait(&s2);
		//sleep(1);
		printf("B");
		if(turn == 2) {
			turn = 1;
			c++;
			sem_post(&s1);
			printf("\n");
		}
		else {
			sem_post(&s3);
			sem_wait(&s2);
			sem_post(&s3);
			sem_wait(&s2);
			turn = 2;
			sem_post(&s1);
		}
	}
}

void* C() {
	while(1){
		sem_wait(&s3);
		//sleep(1);
		printf("C");
		sem_post(&s2);
		
	}
}

int main()
{
	sem_init(&s1, 1, 1);
	sem_init(&s2, 1, 0);
	sem_init(&s3, 1, 0);
	
	pthread_t t1, t2, t3;
	int i1, i2, i3;
	
	
	i1 = pthread_create(&t1, NULL, A, NULL);
	i2 = pthread_create(&t2, NULL, B, NULL);
	i3 = pthread_create(&t3, NULL, C, NULL);

	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);


}

// ABBCCA
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

// Define a Counter Variable.
int c = 0; 

sem_t s1, s2, s3;
int turn = 1;

// A B B C C A

void* A() {
	while(1) {
		sem_wait(&s1);
		printf("A");
    if(turn==1){
		  sem_post(&s2);
    }
    else{
      turn=1;
      printf("\n");
      sem_post(&s1);
    }
    sleep(1);
	}
}

void* B() {
	while(1){
		sem_wait(&s2);
		printf("B");
		if(turn == 2) {
			turn = 1;
			sem_post(&s3);
		}
		else {
			turn =2;
			sem_post(&s2);
		}
	}
}

void* C() {
	while(1){
		sem_wait(&s3);
		printf("C");
    if(turn==1){
		  turn=2;
      sem_post(&s3);
    }
    else{
      turn=2;
      sem_post(&s1);
    }
		
	}
}
sem_t p1,p2;
void* ping(){
  while(1){
    sem_wait(&p1);
    printf("Ping ");
    sem_post(&p2);
    sleep(1);
  }
}
void* pong(){
  while(1){
    sem_wait(&p2);
    printf("Pong\n");
    sem_post(&p1);
    sleep(2);
  }
}
int main()
{
	sem_init(&s1, 1, 1);
	sem_init(&s2, 1, 0);
	sem_init(&s3, 1, 0);
  // sem_init(&p1,0,1);
  // sem_init(&p2,0,0);
  
	pthread_t t1, t2, t3;
	// int i1, i2, i3;
	
	
  pthread_create(&t1, NULL, A, NULL);
	pthread_create(&t2, NULL, B, NULL);
	pthread_create(&t3, NULL, C, NULL);

	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);


}


//ABCACB
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

// Define a Counter Variable.
int c = 0; 

sem_t s1, s2, s3;
int turn = 1;
// "A B C A C B"

void* A() {
	while(1) {
		sem_wait(&s1);
		printf("A");
    if(turn==1){
		  turn=2;
      sem_post(&s2);
    }
    else{
      turn=2;
      sem_post(&s3);
    }
    sleep(1);
	}
}

void* B() {
	while(1){
		sem_wait(&s2);
		printf("B");
		if(turn==1) {
      printf("\n");
			sem_post(&s1);
		}
		else {
			turn=1;
			sem_post(&s3);
		}
	}
}

void* C() {
	while(1){
		sem_wait(&s3);
		printf("C");
    if(turn==2){
      turn=1;
		  sem_post(&s2);
    }
    else{
      turn=2;
      sem_post(&s1);
    }
	}
}
sem_t p1,p2;
void* ping(){
  while(1){
    sem_wait(&p1);
    printf("Ping ");
    sem_post(&p2);
    sleep(1);
  }
}
void* pong(){
  while(1){
    sem_wait(&p2);
    printf("Pong\n");
    sem_post(&p1);
    sleep(2);
  }
}
int main()
{
	sem_init(&s1, 1, 1);
	sem_init(&s2, 1, 0);
	sem_init(&s3, 1, 0);
  // sem_init(&p1,0,1);
  // sem_init(&p2,0,0);
  
	pthread_t t1, t2, t3;
	// int i1, i2, i3;
	
	
  pthread_create(&t1, NULL, A, NULL);
	pthread_create(&t2, NULL, B, NULL);
	pthread_create(&t3, NULL, C, NULL);

	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);


}






















