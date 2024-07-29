//Recursively and non-recursively reverse a linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void display(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node* mkNode(struct node* ptr, int val){
    if (ptr==NULL){
        ptr = (struct node* )malloc(sizeof(struct node));
        ptr->next = NULL;
        ptr->data = val;
        return ptr;
    }
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = (struct node*)malloc(sizeof(struct node));
    ptr = ptr->next;
    ptr->data =val;
    ptr->next = NULL;
    return NULL; 
}

//with recursion
struct node* RecRevLL(struct node* ptr){
    struct node* tmp;
    if(ptr->next->next==NULL){
        ptr->next->next=ptr;
        tmp = ptr->next;
        ptr->next = NULL;
        return tmp;
    }
    tmp = RecRevLL(ptr->next);
    ptr->next->next = ptr;
    ptr->next = NULL;
    return tmp;    
}

//Without recursion
struct node* RevLL(struct node* ptr){
    struct node *p,*q;
    p = NULL; q = NULL;
    while(ptr!=NULL){
        p=q;
        q=ptr;
        ptr=ptr->next;
        q->next = p;
    }
    return q;
}

int main(){
    struct node* HEAD=NULL;
    HEAD = mkNode(HEAD,35);
    mkNode(HEAD,45);
    mkNode(HEAD,75);
    mkNode(HEAD,15);
    mkNode(HEAD,55);
    mkNode(HEAD,90);
    display(HEAD);
    HEAD = RecRevLL(HEAD);//with recursion
    display(HEAD);
    HEAD = RevLL(HEAD);//without recursion
    display(HEAD);
    return 0;
}