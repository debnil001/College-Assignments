#include <stdio.h>
#include <stdlib.h>

struct ThreadedNode {
    int data;
    struct ThreadedNode* left;
    struct ThreadedNode* right;
    int isThreaded;
};

struct ThreadedNode* createThreadedNode(int data, int isThreaded) {
    struct ThreadedNode* newNode = (struct ThreadedNode*)malloc(sizeof(struct ThreadedNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isThreaded = isThreaded;
    return newNode;
}

struct ThreadedNode* insertion(struct ThreadedNode* root, int data) {
    if (root == NULL) {
        return createThreadedNode(data, 0);
    }
    
    if (root->data > data) {
        root->left = insertion(root->left, data);
    } else if (root->data < data) {
        root->right = insertion(root->right, data);
    }
    
    return root;
}

struct ThreadedNode* createThreaded(struct ThreadedNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return root;
    }
    
    if (root->left != NULL) {
        struct ThreadedNode* child = createThreaded(root->left);
        child->right = root;
        child->isThreaded = 1;
    }
    
    if (root->right == NULL) {
        return root;
    }
    
    return createThreaded(root->right);
}

struct ThreadedNode* leftMost(struct ThreadedNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    while (root->left != NULL) {
        root = root->left;
    }
    
    return root;
}

void inorder(struct ThreadedNode* root) {
    struct ThreadedNode* curr = leftMost(root);
    
    while (curr != NULL) {
        printf("%d\n", curr->data);
        
        if (curr->isThreaded) {
            curr = curr->right;
        } else {
            curr = leftMost(curr->right);
        }
    }
}

int main() {
    struct ThreadedNode* root = createThreadedNode(5, 0);
    
    root = insertion(root, 2);
    root = insertion(root, 10);
    root = insertion(root, 20);
    
    createThreaded(root);
    
    inorder(root);
    
    return 0;
}
