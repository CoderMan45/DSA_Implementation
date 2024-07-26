#include <stdio.h>

struct node {
    struct node* lchild;
    struct node* rchild;
    int data;
};

int main(){
    struct node* root = NULL;
    root = (struct node*)malloc(sizeof(struct node));
}