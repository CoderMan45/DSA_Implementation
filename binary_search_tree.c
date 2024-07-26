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
        newNode(ptr->lchild,val);
    }
    else if (ptr->data<val) 
        newNode(ptr->rchild,val);
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
}