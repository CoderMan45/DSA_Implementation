#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

//Add new nodes to linked list
struct node* mkNode(struct node* HEAD, int val){
    if (HEAD == NULL){
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = val;
        ptr->next = NULL;
        return ptr; 
    }
    else{
        struct node* ptr = HEAD;
        while(ptr->next!= NULL){
            ptr = ptr->next;
        }
        ptr->next=(struct node*)malloc(sizeof(struct node));
        ptr = ptr->next;
        ptr->next = NULL;
        ptr->data = val;
        return NULL;
    }
}

void display(struct node* HEAD){
    struct node* ptr = HEAD;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void insertNode(struct node* HEAD, int pos, int val){
    struct node* ptr = HEAD;
    struct node* tmp;
    while(ptr->next->data != pos && ptr != NULL){
        ptr=ptr->next;
    }
    if(ptr == NULL){
        printf("Element not found");
        return;
    }
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = val;
    tmp->next = ptr->next;
    ptr->next = tmp;

}

//Reverse a linked list
struct node* reverseLL(struct node* HEAD){
    struct node* ptr = HEAD;
    if(ptr->next->next!=NULL){
        HEAD = reverseLL(ptr->next);
        ptr->next->next=ptr;
        ptr->next = NULL;
        return HEAD;
    }
    ptr->next->next=ptr;
    struct node* tmp = ptr->next;
    ptr->next = NULL;
    return (tmp);   

}

int main(){
    struct node* HEAD = (struct node*)malloc(sizeof(struct node));
    HEAD = NULL;
    HEAD = mkNode(HEAD,15);
    mkNode(HEAD,45);
    mkNode(HEAD,50);
    mkNode(HEAD,61);
    mkNode(HEAD,13);
    mkNode(HEAD,74);
    display(HEAD);
    printf("\n");
    insertNode(HEAD,50,120);
    display(HEAD);
    printf("\n");
    HEAD = reverseLL(HEAD);
    display(HEAD);


    return 0;
}