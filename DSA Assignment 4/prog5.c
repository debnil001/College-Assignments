#include<stdio.h>
struct BST{
    struct node *left;
    int data;
    struct node *right;
};
struct BST* createNode(int data){
    struct BST *newNode=(struct BST*)malloc(sizeof(struct BST));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void insertion(struct BST **r,int data){
    struct BST *newNode=createNode(data);
    if(*r==NULL){
        *r=newNode;
    }
    else{
        struct BST *temp=*r;
        while(1){
            if(temp->data==newNode->data){
                printf("Insertion not possible\n");
                free(newNode);
                break;
            }
            else if(newNode->data>temp->data){
                if(temp->right==NULL){
                 temp->right=newNode;
                 break;
                }
                temp=temp->right;
            }
            else{
                if(temp->left==NULL){
                    temp->left=newNode;
                    break;
                }
                temp=temp->left;
            }
        }
    }
}
void deletion(struct BST **r,int data){
    struct BST *ptr=*r;
    struct BST *parptr=NULL;
    while(1){
        if(ptr==NULL){
            printf("Node not found");
            break;
        }
        else if(data>ptr->data){
            parptr=ptr;
            ptr=ptr->right;
        }
        else if(data<ptr->data){
            parptr=ptr;
            ptr=ptr->left;
        }
        else{
            if(parptr==NULL){

            }
            if(ptr->left==NULL && ptr->right==NULL){
                if(parptr->left==ptr)
                    parptr->left=NULL;
                else if(parptr->right==ptr)
                    parptr->right=NULL;
                free(ptr);
                break;
            }
            else if(ptr->left==NULL || ptr->right==NULL){
                if(ptr->left==NULL){
                    if(parptr->left==ptr)
                        parptr->left=ptr->right;
                    else
                        parptr->right=ptr->right;
                }
                else if(ptr->right==NULL){
                    if(parptr->left==ptr)
                        parptr->left=ptr->left;
                    else
                        parptr->right=ptr->left;
                }
                free(ptr);
                break;
            }
            else if(ptr->left!=NULL && ptr->right!=NULL){
                struct BST *pred=ptr->left;
                struct BST *parpred=NULL;
                while(pred->right!=NULL){
                    parpred=pred;
                    pred=pred->right;
                }
                if(parpred==NULL){
                    ptr->data=pred->data;
                    ptr->left=pred->left;
                    free(pred);
                }
                else{
                    ptr->data=pred->data;
                    parpred->right=pred->left;
                    free(pred);
                }
                break;
            }
        }
    }
}
void inorder(struct BST *r){
    if(r!=NULL){
    inorder(r->left);
    printf("%d ",r->data);
    inorder(r->right);
    }
}
main(){
    struct BST *root=NULL;
    insertion(&root,50);
    insertion(&root,30);
    insertion(&root,80);
    insertion(&root,10);
    insertion(&root,70);
    insertion(&root,90);
    insertion(&root,60);
    insertion(&root,75);
    insertion(&root,77);
    insertion(&root,65);
    inorder(root);
    printf("\n");
    deletion(&root,10);
    inorder(root);
    printf("\n");
    deletion(&root,60);
    inorder(root);
    printf("\n");
    deletion(&root,80);
    inorder(root);
    printf("\n");
}