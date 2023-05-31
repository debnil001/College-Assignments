#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void createBinaryTree(int tree[], int index) {
    int data;

    printf("Enter data for node %d (-1 for empty node): ", index);
    scanf("%d", &data);

    if (data == -1) {
        tree[index] = -1;
        return;
    }

    tree[index] = data;

    printf("Enter left child of %d\n", data);
    createBinaryTree(tree, 2 * index + 1);

    printf("Enter right child of %d\n", data);
    createBinaryTree(tree, 2 * index + 2);
}

void preorderTraversal(int tree[], int index) {
    if (tree[index] == -1)
        return;

    printf("%d ", tree[index]);
    preorderTraversal(tree, 2 * index + 1);
    preorderTraversal(tree, 2 * index + 2);
}

void inorderTraversal(int tree[], int index) {
    if (tree[index] ==-1)
        return;

    inorderTraversal(tree, 2 * index + 1);
    printf("%d ", tree[index]);
    inorderTraversal(tree, 2 * index + 2);
}

void postorderTraversal(int tree[], int index) {
    if (tree[index]==-1)
        return;

    postorderTraversal(tree, 2 * index + 1);
    postorderTraversal(tree, 2 * index + 2);
    printf("%d ", tree[index]);
}

int main() {
    int tree[MAX_SIZE];
    int choice, size, i;

    printf("Binary Tree Operations:\n");
    printf("1. Create Binary Tree\n");
    printf("2. Preorder Traversal\n");
    printf("3. Inorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the root value of the binary tree:\n");
                createBinaryTree(tree, 0);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(tree, 0);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(tree, 0);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(tree, 0);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
