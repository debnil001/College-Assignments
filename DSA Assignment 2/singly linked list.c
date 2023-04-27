#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
    int size;
};
void traverse(struct node **s){
   struct node *temp=*s;
   while(temp!=NULL){
    printf("%d  ",temp->data);
    temp=temp->next;
   }
   printf("\n\n");
}
struct node* createNode(int data){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
    newNode->size=1;
    return newNode;
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
        (*s)->size++;
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
        (*s)->size++;
    }
}
void addBeforeKth(struct node** head_ref, int data, int k) {
   struct node* new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data = data;

   if (k == 1) {
       new_node->next = *head_ref;
       *head_ref = new_node;
       return;
   }

   struct node* prev = *head_ref;
   int i;
   for ( i = 1; i < k - 1 && prev != NULL; i++) {
       prev = prev->next;
   }

   if (prev == NULL) {
       printf("Error: List is shorter than %d nodes.\n", k - 1);
       return;
   }

   new_node->next = prev->next;
   prev->next = new_node;
}
void addAfterKth(struct node* head, int data, int k) {

   struct node* new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data = data;

   struct node* current = head;
   int i;
   for (i = 1; i < k && current != NULL; i++) {
       current = current->next;
   }

   if (current == NULL) {
       printf("Error: List is shorter than %d nodes.\n", k);
       return;
   }

   new_node->next = current->next;
   current->next = new_node;
}
void insertAfterGivenValue(struct node* head, int searchValue, int newValue) {
   struct node* current = head;
   while (current != NULL) {
       if (current->data == searchValue) {
           struct node* newNode = (struct node*) malloc(sizeof(struct node));
           newNode->data = newValue;
           newNode->next = current->next;
           current->next = newNode;
           return;
       }
       current = current->next;
   }
   printf("node with value %d not found.\n", searchValue);
}
void insertBeforeGivenValue(struct node** head, int value, int newValue) {
   struct node* newNode = (struct node*) malloc(sizeof(struct node));
   newNode->data = newValue;
   newNode->next = NULL;
   if (*head == NULL) {
       *head = newNode;
       return;
   }
   if ((*head)->data == value) {
       // newNode->next = *head;
       // *head = newNode;
       insertAtBegin(head,value);
       return;
   }
   struct node* current = *head;
   while (current->next != NULL && current->next->data != value) {
       current = current->next;
   }
   if (current->next == NULL) {
       printf("Value not found in the list.\n");
       return;
   }
   newNode->next = current->next;
   current->next = newNode;
}

void insertAtPosition(struct node **s,int pos,int data){
    if(countNode(s)<pos||pos<0){
        printf("Please enter valid position");
    }
    else{
        struct node *newNode=createNode(data);
        struct node *temp=*s;
        int i;
        for(i=1;i<pos;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
void removeFirst(struct node **s){
struct node *r;
if(*s){
    r=*s;
    *s=r->next;
    free(r);
}
}
void removeLast(struct node **s){
struct node *t1,*t2;
if(*s==NULL)
    printf("\nUnderflow\n");
else{
    t1=*s;
    t2=NULL;
    while(t1->next!=NULL)
       t1=t1->next;
    free(t1);
    if(t2==NULL)
        *s=NULL;
    else
        t2->next=NULL;
}
}
void removeAtPos(struct node **s,int pos){
	if(countNode(s)-1<pos||pos<0){
        printf("Please enter valid position");
    }
    else{
        struct node *temp=*s;
        int i;
        for(i=1;i<pos;i++)
            temp=temp->next;
    struct node *next = temp->next->next;
    free(temp->next);  // Free memory
    temp->next = next;
    }
}
void deleteAfterkth(struct node* head, int k) {
    int count = 0;
    struct node* current = head;
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }
    if (current != NULL && current->next != NULL) {
        struct node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}
void deleteBeforekth(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k <= 1) {
        return;
    }
    struct node* current = head;
    struct node* prev = NULL;
    int count = 1;
    while (current != NULL && count < k) {
        prev = current;
        current = current->next;
        count++;
    }
    if (current != NULL) {
        prev->next = current->next;
        free(current);
    }
}
void reverse(struct node **s){
	struct node *t1,*t2;
	t1=(*s)->next;
	(*s)->next=NULL;
	t2=t1->next;
	while(1){
		t1->next=*s;
		*s=t1;
		t1=t2;
		if(t1==NULL)
		break;
		t2=t2->next;
	}
}
void deletekthNode(struct node** head, int k) {
    if (*head == NULL || k <= 0) {
        return;
    }
    struct node* current = *head;
    struct node* prev = NULL;
    int count = 1;
    while (current != NULL && count < k) {
        prev = current;
        current = current->next;
        count++;
    }
    if (current != NULL) {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    }
}
void deleteNode(struct node** head, int value) {
   if (*head == NULL) {
       return;
   }
   struct node* current = *head;
   struct node* prev = NULL;
   while (current != NULL) {
       if (current->data == value) {
           if (prev == NULL) {
               *head = current->next;
           } else {
               prev->next = current->next;
           }
           free(current);
           return;
       }
       prev = current;
       current = current->next;
   }
}
struct node* getMiddle(struct node* head){
        struct node* slow=head;
        struct node* fast=(head)->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
}
void splitList(struct node* head, struct node** left, struct node** right) {
    struct node* fast = head->next;
    struct node* slow = head;

    while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}
struct node* merge(struct node* left, struct node* right) {
    struct node* result = NULL;

    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    }

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}
void getList(struct node* ll1,struct node *ll2){
    int len1,len2;
    printf("Enter length of 1st linked list::");
    scanf("%d",&len1);
    printf("Enter 1st linked list value(value would be inserted at end):\n");
    int val;
    int i;
    for(i=1;i<=len1;i++){
        scanf("%d",&val);
        insertAtLast(&ll1,val);
    }
    // getchar();
    printf("Enter length of 2nd linked list::");
    scanf("%d",&len2);
    printf("Enter 2nd linked list value(value would be inserted at end):\n");
    for(i=1;i<=len2;i++){
        scanf("%d",&val);
        insertAtLast(&ll2,val);
    }
}
void mergeTwoList(){
    struct node* ll1=NULL;
    struct node* ll2=NULL;
    int len1,len2;
    printf("Enter length of 1st linked list::");
    scanf("%d",&len1);
    printf("Enter 1st linked list value(value would be inserted at end):\n");
    int val;
    int i;
    for(i=1;i<=len1;i++){
        scanf("%d",&val);
        insertAtLast(&ll1,val);
    }
    // getchar();
    printf("Enter length of 2nd linked list::");
    scanf("%d",&len2);
    printf("Enter 2nd linked list value(value would be inserted at end):\n");
    for(i=1;i<=len2;i++){
        scanf("%d",&val);
        insertAtLast(&ll2,val);
    }
    struct node* mergedLL=merge(ll1,ll2);
    printf("Merged list is::");
    traverse(&mergedLL);
}
void mergeSort(struct node** head) {
    struct node* current = *head;
    struct node* left = NULL;
    struct node* right = NULL;

    if (current == NULL || current->next == NULL) {
        return;
    }

    splitList(current, &left, &right);
    mergeSort(&left);
    mergeSort(&right);

    *head = merge(left, right);
}
// void concat(struct node **ll1,struct node **ll2){
//     // while(temp->next!=NULL){
//     //     temp=temp->next;
//     // }
//     struct node *temp=*ll2;
//     while (temp!=NULL)
//     {
//         insertAtLast(&ll1,temp->data);
//         temp=temp->next;
//     }    
// }
// struct node* mergeSort(struct node* head){
//         if(head==NULL || (head)->next==NULL)
//             return head;
//         struct node* mid=getMiddle(head);
// //        printf("%d\n",mid->data);
//         struct node* rightHead=mid->next;
//         mid->next=NULL;
//                traverse(&head);
//         traverse(&rightHead);
//         struct node* left=mergeSort(head);
//         struct node* right=mergeSort(rightHead);
//         return merge(&left,&right);
// }
int compare_lists(struct node* head1, struct node* head2) {
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data != temp2->data) {
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 || temp2) {
        return 0;
    }

    return 1;
}
struct node* concat_lists(struct node** head1, struct node** head2) {
    if (*head1 == NULL) {
        return *head2;
    }

    struct node* temp = *head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *head2;

    return *head1;
}
void concat(){
	struct node* ll1=NULL;
    struct node* ll2=NULL;
	int len1,len2;
    printf("Enter length of 1st linked list::");
    scanf("%d",&len1);
    printf("Enter 1st linked list value(value would be inserted at end):\n");
    int val;
    int i;
    for(i=1;i<=len1;i++){
        scanf("%d",&val);
        insertAtLast(&ll1,val);
    }
    // getchar();
    printf("Enter length of 2nd linked list::");
    scanf("%d",&len2);
    printf("Enter 2nd linked list value(value would be inserted at end):\n");
    for(i=1;i<=len2;i++){
        scanf("%d",&val);
        insertAtLast(&ll2,val);
    }
    concat_lists(&ll1,&ll2);
    traverse(&ll1);
}

int search_list(struct node* head, int key) {
    struct node* temp = head;
    int index = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; // if key not found
}
int val;
void getVal(){
    printf("Enter node value::");
    scanf("%d",&val);
}
int main(){
    struct node* start=NULL;
    struct node *ll1=NULL,*ll2=NULL;
        int k;
    while(1){
    printf("I. Create a linked list.\n"
"II. Print the content of the list.\n"
"III. Insert an element at the front of the list\n"
"IV. Insert an element at the end of the list"
"\nV. Insert a node after the kth node."
"\nVI. Insert a node after the node (first from the start) containing a"
"given value."
"\nVII. Insert a node before the kth node."
"\nVIII. Insert a node before the node (first from the start) containing a"
"given value."
"\nIX. Delete the first node."
"\nX. Delete the last node."
"\nXI. Delete a node after the kth node."
"\nXII. Delete a node before the kth node."
"\nXIII. Delete the kth node."
"\nXIV. Delete the node(first from the start) containing a specified value."
"\nXV. Find the reverse of a list(not just printing in reverse)"
"\nXVI. Sort the list"
"\nXVII. Search a given element\n"
"XVIII. Merge two lists; those are in ascending order.\n"
"XIX. Concatenate two list\n"
"XX. Find if two lists are equal(Boolean output)\n");
    printf("\n\nEnter choice::");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        getVal();
        start=createNode(val);
        break;
    case 2:
        traverse(&start);
        break;
    case 3:
        getVal();
        insertAtBegin(&start,val);break;
    case 4:
        getVal();
        insertAtLast(&start,val);break;
    case 5:
        getVal();
        printf("Enter K value::");
        scanf("%d",&k);
        addAfterKth(start,val,k);break;
    case 6:
        getVal();
        printf("Enter value::");
        scanf("%d",&k);
        insertAfterGivenValue(start,k,val);break;
    case 7:
        getVal();
        printf("Enter K value::");
        scanf("%d",&k);
        addBeforeKth(&start,val,k);
        break;
    case 8:
        getVal();
        printf("Enter value::");
        scanf("%d",&k);
        insertBeforeGivenValue(&start,k,val);break;
    case 9:
        removeFirst(&start);
        break;
    case 10:
        removeLast(&start);
        break;
    case 11:
        printf("Enter K value::");
        scanf("%d",&k);
        deleteAfterkth(start,k);
        break;
    case 12:
        printf("Enter K value::");
        scanf("%d",&k);
        deleteBeforekth(start,k);
        break;
    case 13:
        printf("Enter K value::");
        scanf("%d",&k);
        deletekthNode(&start,k);
    case 14:
        getVal();
        deleteNode(&start,val);
		break;
    case 15:
        reverse(&start);
        break;
    case 16:
        mergeSort(&start);
        break;
    case 17:
        printf("Enter value to search::");
        scanf("%d",&val);
        search_list(start,val);    
        break;
    case 18:
        mergeTwoList();
        break;
    case 19:
    	concat();
        break;
    case 20:
        getList(ll1,ll2);
        compare_lists(ll1,ll2);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}
return 0;
}
