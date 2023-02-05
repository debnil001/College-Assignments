#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
struct node* createNode(int data){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
}
int countNode(struct node **s){
    int count=0;
    struct node *temp=*s;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void insertAtLast(struct node **s,int data){
	struct node *newNode=createNode(data);
	if(*s==NULL){
        *s=newNode;
	}
	else{
        struct node *temp=*s;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
	}
}

void insertAtBegin(struct node **s,int data){
    struct node *newNode=createNode(data);
    if(*s==NULL){
        *s=newNode;
    }
    else{
        struct node *temp=*s;
        *s=newNode;
        newNode->next=temp;
    }
}

void deleteNode(struct node** head_ref, int key){
    struct node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
  
    if (temp == NULL)
        return;
  
    prev->next = temp->next; 
    free(temp); // Free memory
}

void search(struct node **s,int key){
	struct node *temp=*s;
	while(temp!=NULL){
		if(temp->data==key){
			printf("Element is present");
			return;
		}
		temp=temp->next;
	}
	if(temp==NULL)
		printf("Element is not present");
}

void traverse(struct node **s){
   struct node *temp=*s;
   while(temp!=NULL){
    printf("%d  ",temp->data);
    temp=temp->next;
   }
   printf("\n");
}
main(){
	struct node *start=NULL;
	insertAtLast(&start,25);
	insertAtLast(&start,35);
	insertAtLast(&start,45);
	traverse(&start);
	insertAtBegin(&start,15);
	insertAtBegin(&start,5);
	traverse(&start);
    traverse(&start);
    traverse(&start);
    reverse(&start);
    traverse(&start);
    reverse(&start);
    traverse(&start);
    deleteNode(&start,5);
    traverse(&start);
    search(&start,25);
}
