#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int cqueue[SIZE];
int rear=-1;
int front=-1;

int isFull(){
	return (rear+1)%SIZE==front;
}

int isEmpty(){
	return front==-1;
}

void add(int val){
	if(isFull()){
		printf("Queue is full\n");
		return;
	}
	if(front==-1)
		front=0;
	rear=(rear+1)%SIZE;
	cqueue[rear]=val;
}

void delete(){
	if(isEmpty()){
		printf("Queue is empty\n");
		return;
	}
	if(front==rear)
		front=rear=-1;
	else{
		printf("%d removed!\n",cqueue[front]);
		front=(front+1)%SIZE;	
	}
}

void peek(){
	if(!isEmpty()){
		printf("Peek element is::%d",cqueue[front]);
		return;
	}

	else
		printf("Queue is empty\n");
}

void display(){
	if(isEmpty()){
		printf("Queue is empty\n");
		return;
	}
	int i;
	for(i=front;i!=rear;i=(i+1)%SIZE){
		printf("%d ",cqueue[i]);
	}
}




int main(){	
	add(10);
	add(20);
	add(30);
	add(60);
	add(70);
	add(90);

	delete();
	add(30);		

	display();
}



