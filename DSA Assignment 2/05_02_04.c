#include <stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
void reverseList(struct Node **head) 
{
    struct Node *prev, *cur, *next, *last;

    if (*head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }

    last = *head;

    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;
    while (*head != last)
    {
        *head = (*head)->next;
        cur->next = prev;

        prev = cur;
        cur  = *head;
    }

    cur->next = prev;
    *head = prev;      
}
int josephusCircularLinkedList(int n, int k,int pos,int dir) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* curr = (Node*)malloc(sizeof(Node));
        curr->data = i;
        prev->next = curr;
        prev = curr;
    }
    prev->next = head;
	if(dir==2)
		reverseList(&head);
    Node* curr = head;
    while (curr->next != curr) {
        for (int i = pos; i < k-1; i++) {
            curr = curr->next;
        }        
        Node* temp = curr->next;
        curr->next = curr->next->next;
        curr = curr->next;
        free(temp);
    }
    
    int result = curr->data;
    free(curr);
    return result;
}

int josephusCircularDLinkedList(int n, int k,int pos,int dir) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* curr = (Node*)malloc(sizeof(Node));
        curr->data = i;
        prev->next = curr;
        curr->prev = prev;
        prev = curr;
    }
    prev->next = head;
    head->prev = prev;
    
    Node* curr = head;
    while (curr->next != curr) {
        for (int i = pos; i < k; i++) {
			if(dir==2)
				curr=curr->prev;
			else
            	curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    int result = curr->data;
    free(curr);
    return result;
}
void reverseArray(int *arr,int n){
	int i;
	for(i=0;i<n/2;i++){
	int temp=arr[i];
	arr[i]=arr[n-i-1];
	arr[n-i-1]=arr[i];	
	}

}
int josephus_2DArray(int n, int k,int pos,int dir) {
    int** people = (int**)malloc(2 * sizeof(int*));
    for (int i=0;i<2; i++) {
        people[i]=(int*)malloc(n*sizeof(int));
        for (int j=0;j<n;j++) {
            people[i][j] = j + 1;
        }
    }
    if(dir==2){
		reverseArray(people[0],n);
	}
    int remaining = n;
    int i = pos-1;
    int temp;
    while (remaining > 1) {
        i = (i + k - 1) % remaining;//ith person to be killed
        people[1][people[0][i]-1] = -1;
        for (int j = i; j < remaining - 1; j++) {
                people[0][j] = people[0][j+1];
        }
        remaining--;
    }
    int result = people[0][0];
    printf("\n");
    return result;
}
int main() {
    int n;
    int k;
	printf("Enter number of people::");
	scanf("%d",&n);
	printf("Enter k::");
	scanf("%d",&k);
	int pos;
	printf("Enter position to start::");
	scanf("%d",&pos);
	int dir;
	printf("Enter direction clockwise(1)/anticlockwise(2)::");
	scanf("%d",&dir);
	printf("1.2D Array\n2.Circular Linked List\n3.Circular Doubly Linked List");
	printf("\nEnter choice::");
	int choice;
	scanf("%d",&choice);	
	int result;	
	switch(choice){
		case 1:	
		result=josephus_2DArray(n,k,pos,dir);
		break;
		case 2:
	    result = josephusCircularLinkedList(n, k,pos,dir);
		break;		
		case 3:
	    result = josephusCircularDLinkedList(n, k,pos,dir);
		break;
	}
    for(int i=1;i<=n;i++) {
         printf(" %d|",i);
    }
    printf("\n");
    for(int i=1;i<=n;i++) {
         if(i==result)
             printf(" %d |",result);
         else
         printf("X |");
     }
    printf("\n\nThe winner is %d\n", result);
    return 0;
}

