#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next; 
};

struct node* enque(struct node* ptr, int val){
    if (ptr==NULL){
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = val;
        ptr->next = NULL;
        return ptr;
    }    
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next = (struct node*)malloc(sizeof(struct node));
    ptr = ptr->next;
    ptr->next = NULL;
    ptr->data = val;
}

struct node* deque(struct node* ptr){
    if(ptr==NULL){
        printf("Queue underflow\n");
        return NULL;
    }
    else if (ptr->next==NULL){
        free(ptr);
        return NULL;
    }
    else{
        struct node* tmp;
        tmp = ptr;
        ptr = ptr->next;
        free(tmp);
        return ptr;
    }
}


void display(struct node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct node* HEAD;
    HEAD = NULL;
    HEAD = enque(HEAD,40);
    enque(HEAD,76);
    enque(HEAD,37);
    enque(HEAD,11);
    enque(HEAD,45);
    enque(HEAD,22);
    enque(HEAD,64);
    display(HEAD);
    printf("\n");

    HEAD = deque(HEAD);
    HEAD = deque(HEAD);
    HEAD = deque(HEAD);
    display(HEAD);
    printf("\n");

    enque(HEAD,55);
    display(HEAD);
    printf("\n");

}