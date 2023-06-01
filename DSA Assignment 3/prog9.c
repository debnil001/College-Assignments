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

	queue Q;
	initializeQueue(&Q,6);

	enqueue(&Q,10);
	enqueue(&Q,20);
	enqueue(&Q,30);
	enqueue(&Q,40);
	dequeue(&Q);
	display_queue(&Q);
}
