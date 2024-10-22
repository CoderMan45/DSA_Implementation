#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next; 
};

struct node* push(struct node* ptr, int val){
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

void pop(struct node* ptr){
    if(ptr==NULL){
        printf("Stack underflow\n");
    }
    else if (ptr->next==NULL)
        free(ptr);
    else{
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
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
    HEAD = push(HEAD,40);
    push(HEAD,76);
    push(HEAD,37);
    push(HEAD,11);
    push(HEAD,45);
    push(HEAD,22);
    push(HEAD,64);
    display(HEAD);
    printf("\n");

    pop(HEAD);
    pop(HEAD);
    pop(HEAD);
    display(HEAD);
    printf("\n");

    push(HEAD,55);
    display(HEAD);
    printf("\n");

}