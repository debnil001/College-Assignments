#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* createNode(int data){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void insertAtBegin(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    new_node->prev = NULL;
    if ((*head) != NULL) {
        (*head)->prev = new_node;
    }
    (*head) = new_node;
}
void insertAtEnd(struct node** head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}
void insert_after_k(struct node** head, int data, int k) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    // Traverse the list to find the kth node
    struct node* current = *head;
    int count = 1;
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    if (current != NULL) {
        // Insert the new node after the kth node
        new_node->next = current->next;
        new_node->prev = current;
        if (current->next != NULL) {
            current->next->prev = new_node;
        }
        current->next = new_node;
    } else {
        // If the kth node is not found, insert the new node at the end of the list
        new_node->next = NULL;
        if (*head == NULL) {
            new_node->prev = NULL;
            *head = new_node;
        } 
        else {
            // Traverse the list to find the last node
            current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            // Insert the new node at the end of the list
            current->next = new_node;
            new_node->prev = current;
        }
    }
}
void insert_after_value(struct node** head, int data, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    // Traverse the list to find the node containing the given value
    struct node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current != NULL) {
        // Insert the new node after the node containing the given value
        new_node->next = current->next;
        new_node->prev = current;
        if (current->next != NULL) {
            current->next->prev = new_node;
        }
        current->next = new_node;
    } else {
        // If the node containing the given value is not found, insert the new node at the end of the list
        new_node->next = NULL;
        if (*head == NULL) {
            // If the list is empty, set the new node as the head
            new_node->prev = NULL;
            *head = new_node;
        } else {
            // Traverse the list to find the last node
            current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            // Insert the new node at the end of the list
            current->next = new_node;
            new_node->prev = current;
        }
    }
}
void insert_before_k(struct node** head, int data, int k) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    // Traverse the list to find the kth node
    struct node* current = *head;
    int count = 1;
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    if (current != NULL) {
        // Insert the new node before the kth node
        new_node->next = current;
        new_node->prev = current->prev;
        if (current->prev != NULL) {
            current->prev->next = new_node;
        } else {
            *head = new_node; // Update the head pointer if the new node is inserted at the beginning
        }
        current->prev = new_node;
    } else {
        // If the kth node is not found, insert the new node at the end of the list
        new_node->next = NULL;
        if (*head == NULL) {
            // If the list is empty, set the new node as the head
            new_node->prev = NULL;
            *head = new_node;
        } else {
            // Traverse the list to find the last node
            current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            // Insert the new node at the end of the list
            current->next = new_node;
            new_node->prev = current;
        }
    }
}
void insert_before_value(struct node** head, int data, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    // Traverse the list to find the node containing the given value
    struct node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current != NULL) {
        // Insert the new node before the node containing the given value
        new_node->next = current;
        new_node->prev = current->prev;
        if (current->prev != NULL) {
            current->prev->next = new_node;
        } else {
            *head = new_node; // Update the head pointer if the new node is inserted at the beginning
        }
        current->prev = new_node;
    } else {
        // If the node containing the given value is not found, insert the new node at the end of the list
        new_node->next = NULL;
        if (*head == NULL) {
            // If the list is empty, set the new node as the head
            new_node->prev = NULL;
            *head = new_node;
        } else {
            // Traverse the list to find the last node
            current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            // Insert the new node at the end of the list
            current->next = new_node;
            new_node->prev = current;
        }
    }
}

void delete_first_node(struct node** head) {
    if (*head == NULL) {
        // List is empty, nothing to delete
        return;
    }

    struct node* temp = *head;

    if (temp->next != NULL) {
        // There are other nodes in the list
        temp->next->prev = NULL;
        *head = temp->next;
    } else {
        // This is the only node in the list
        *head = NULL;
    }

    free(temp);
}


void delete_last_node(struct node** head) {
    if (*head == NULL) {
        // List is empty, nothing to delete
        return;
    }

    struct node* current = *head;

    // Traverse the list to find the last node
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        // The last node is not the head node
        current->prev->next = NULL;
    } else {
        // The last node is the head node
        *head = NULL;
    }

    free(current);
}
void delete_node_after_k(struct node* head, int k) {
    if (head == NULL || head->next == NULL) {
        // List is empty or has only one node, nothing to delete
        return;
    }

    struct node* current = head;
    int count = 0;

    // Traverse the list to find the kth node
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        // There are not enough nodes in the list, nothing to delete
        return;
    }

    struct node* temp = current->next;
    current->next = temp->next;

    if (temp->next != NULL) {
        // The node to delete is not the last node
        temp->next->prev = current;
    }

    free(temp);
}
void delete_node_before_k(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k <= 1) {
        // List is empty, has only one node or k is invalid, nothing to delete
        return;
    }

    struct node* current = head;
    int count = 1;

    // Traverse the list to find the kth node
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->prev == NULL) {
        // There are not enough nodes in the list or no node to delete, nothing to delete
        return;
    }

    struct node* temp = current->prev;
    temp->prev->next = current;
    current->prev = temp->prev;

    free(temp);
}
void delete_node_k(struct node** head, int k) {
    if (*head == NULL) {
        // List is empty, nothing to delete
        return;
    }

    struct node* current = *head;
    int count = 1;

    // Traverse the list to find the kth node
    while (current != NULL && count < k) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        // There are not enough nodes in the list, nothing to delete
        return;
    }

    if (current == *head) {
        // Deleting the first node
        *head = current->next;
    }

    if (current->next != NULL) {
        // The node to delete is not the last node
        current->next->prev = current->prev;
    }

    if (current->prev != NULL) {
        // The node to delete is not the first node
        current->prev->next = current->next;
    }

    free(current);
}
void delete_node_by_value(struct node** head, int value) {
    if (*head == NULL) {
        // List is empty, nothing to delete
        return;
    }

    struct node* current = *head;

    // Traverse the list to find the node with the specified value
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        // The node with the specified value is not found, nothing to delete
        return;
    }

    if (current == *head) {
        // Deleting the first node
        *head = current->next;
    }

    if (current->next != NULL) {
        // The node to delete is not the last node
        current->next->prev = current->prev;
    }

    if (current->prev != NULL) {
        // The node to delete is not the first node
        current->prev->next = current->next;
    }

    free(current);
}
void reverse_list(struct node** head) {
    struct node* current = *head;
    struct node* temp = NULL;

    while (current != NULL) {
        // Swap next and prev pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node
        current = current->prev;
    }

    if (temp != NULL) {
        // Update the head pointer to point to the last node
        *head = temp->prev;
    }
}
void traverse(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int val;
void getVal(){
    printf("Enter node value::");
    scanf("%d",&val);
}
int main(){
    struct node* start=NULL;
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
"\nXV. Find the reverse of a list(not just printing in reverse)");
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
        traverse(start);
        break;
    case 3:
        getVal();
        insertAtBegin(&start,val);break;
    case 4:
        getVal();
        insertAtEnd(&start,val);break;
    case 5:
        getVal();
        printf("Enter K value::");
        scanf("%d",&k);
        insert_after_k(&start,val,k);
        break;
    case 6:
        getVal();
        printf("Enter value::");
        scanf("%d",&k);
        insert_after_value(&start,k,val);
        break;
    case 7:
        getVal();
        printf("Enter K value::");
        scanf("%d",&k);
        insert_before_k(&start,val,k);
        break;
    case 8:
        getVal();
        printf("Enter value::");
        scanf("%d",&k);
        insert_before_value(&start,k,val);break;
    case 9:
        delete_first_node(&start);
        break;
    case 10:
        delete_last_node(&start);
        break;
    case 11:
        printf("Enter K value::");
        scanf("%d",&k);
        delete_node_after_k(start,k);
        break;
    case 12:
        printf("Enter K value::");
        scanf("%d",&k);
        delete_node_before_k(start,k);
        break;
    case 13:
        printf("Enter K value::");
        scanf("%d",&k);
        delete_node_k(&start,k);
    case 14:
        getVal();
        delete_node_by_value(&start,val);
		break;
    case 15:
        reverse_list(&start);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}
return 0;
}
