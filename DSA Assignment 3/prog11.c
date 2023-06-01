#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int *arr;
  int front;
  int rear;
  int size;
}queue;

void initializeQueue(queue *q, int size) {
  q->arr=(int*)malloc(sizeof(int) * size);
  q->front= -1;
  q->rear= -1;
  q->size= size;
}

int is_empty(queue *q) {
  return q->front == -1;
}

int is_full(queue *q) {
  return q->rear == q->size - 1;
}

void enqueue(queue *q, int data) {
  if (is_full(q)) {
    printf("Queue is full\n");
    return;
  }
  if(q->front==-1)
	q->front=0;
  q->rear++;
  q->arr[q->rear] = data;
}


int dequeue(queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return -1;
  }

  int data = q->arr[q->front];
  q->front++;
  return data;
}


void appendQueue(queue *x,queue *y){
	int i;
	for(i=x->front;i<=(x->rear);i++){
		enqueue(y,x->arr[i]);
	}
}


void display_queue(queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return;
  }

  for (int i=q->front;i<=q->rear;i++) {
    printf("%d\n", q->arr[i]);
  }
}

int main(){

	queue Q1;
	initializeQueue(&Q1,6);
	queue Q2;
	initializeQueue(&Q2,10);
	enqueue(&Q1,10);
	enqueue(&Q1,20);
	enqueue(&Q1,30);
	enqueue(&Q1,40);
	dequeue(&Q1);
	printf("Queue1 elements::\n");
	display_queue(&Q1);
	enqueue(&Q2,100);
	enqueue(&Q2,200);
	printf("Queue2 elements::\n");
	display_queue(&Q2);	
	printf("Appending Q1 at the end of Q2\n");
	appendQueue(&Q1,&Q2);
	printf("After appending Q1 at the end of Q2\n");
	display_queue(&Q2);
}
