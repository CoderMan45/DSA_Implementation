#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* lchild;
    struct node* rchild;
    int data;
};

struct node* newNode(struct node* ptr, int val){
    if (ptr==NULL){
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->lchild = NULL;
        ptr->rchild = NULL;
        ptr->data = val;
        return ptr;
    }
    if (ptr->data>val){
        if (ptr->lchild == NULL){
            ptr->lchild = (struct node*)malloc(sizeof(struct node));
            ptr = ptr->lchild;
            ptr->lchild = NULL;
            ptr->rchild = NULL;
            ptr->data = val;
        }
        else newNode(ptr->lchild,val);
    }
    else 
    if (ptr->rchild == NULL){
            ptr->rchild = (struct node*)malloc(sizeof(struct node));
            ptr = ptr->rchild;
            ptr->lchild = NULL;
            ptr->rchild = NULL;
            ptr->data = val;
        }
    else newNode(ptr->rchild,val);
}

void preorder(struct node* ptr){
    if (ptr==NULL)
        return;
    else{
        printf("%d ",ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);        
    }
}

void postorder(struct node* ptr){
    if (ptr==NULL)
        return;
    else{
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ",ptr->data);        
    }
}

void inorder(struct node* ptr){
    if (ptr==NULL)
        return;
    else{
        inorder(ptr->lchild);
        printf("%d ",ptr->data);     
        inorder(ptr->rchild);           
    }
}

int main(){
    struct node* root = NULL;
    root = newNode(root,50);
    newNode(root,14);
    newNode(root,86);
    newNode(root,40);
    newNode(root,70);
    newNode(root,24);
    newNode(root,51);
    newNode(root,23);
    
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    
    printf("Inorder: ");
    inorder(root);
    printf("\n");
}