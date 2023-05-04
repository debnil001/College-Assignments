/*
#include <iostream>
#include <queue> // include the queue library
using namespace std;

int findTheWinner(int n, int k) {

	queue<int> q; // create a queue to store the players

	// add all players to the queue
	int i=1;
	while(i<=n){
		q.push(i);
		i++;
	}

	// loop until there is only one player left in the queue
	while(q.size()!=1){

		// move the first k-1 players from front to back of the
	//queue in circular manner
		int j=1;
		while(j<k){
			int temp=q.front();
			q.push(temp);
			q.pop();
			j++;
		}

		// remove the kth player from the front of the queue and eliminate them
		q.pop();
	}

	// return the last remaining player as the winner of the game
	return q.front();
}

int main() {
	int n=4, k=2; // set n and k to the desired values

	// call the findTheWinner function and store the result in ans
	int ans = findTheWinner(n,k);

	// print the winner to the console
	cout << "The winner is player " << ans << endl;
	return 0; // indicate successful program termination
}


*/

#include <stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

int josephusCircularLinkedList(int n, int k) {
    // Create a circular doubly linked list of people
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
    
    Node* curr = head;
    while (curr->next != curr) {// continue untill one node is left
        for (int i = 1; i < k-1; i++) {
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

int josephusCircularDLinkedList(int n, int k) {
    // Create a circular doubly linked list of people
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
    while (curr->next != curr) {// continue untill one node is left
        for (int i = 1; i < k; i++) {
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
int josephus_2DArray(int n, int k) {
    int** people = (int**)malloc(2 * sizeof(int*));
    for (int i=0;i<2; i++) {
        people[i]=(int*)malloc(n*sizeof(int));
        for (int j=0;j<n;j++) {
            people[i][j] = j + 1;
        }
    }
    
    int remaining = n;
    int i = 0;
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
    printf("%d\n", result);
    for(int j=0;j<n;j++)
        printf("%d ",people[1][j]);
    printf("\n");
    return result;
}
int main() {
    int n = 5; // Number of people
    int k = 3;  // Elimination pattern
    int result = josephus_2DArray(n, k);
    // for(int i=1;i<=n;i++) {
    //     printf(" %d|",i);
    // }
    // printf("\n");
    // for(int i=1;i<=n;i++) {
    //     if(i==result)
    //         printf("  |",result);
    //     else
    //     printf("X |");
    // }
    printf("\n\nThe winner is %d\n", result);
    return 0;
}
