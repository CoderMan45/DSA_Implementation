#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* addNode(struct node* HEAD, int data){
    struct node* ptr;
    if (HEAD==NULL){
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = data;
        ptr->next = NULL;
    }
    else{
        ptr = HEAD;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = (struct node*)malloc(sizeof(struct node));
        ptr = ptr->next;
        ptr->data = data;
        ptr->next = NULL;
    }
    return ptr;
}

void dispLL(struct node* HEAD){
    while (HEAD != NULL){
        printf("%d ",HEAD->data);
        HEAD = HEAD->next;
    }
    printf("\n");
}

struct node* midLL(struct node* HEAD){
    struct node *ptr1=HEAD, *ptr2 = HEAD->next;
    while (ptr2 != NULL) {
        ptr2 = ptr2->next;
        if (ptr2 != NULL) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    return ptr1;
}

struct node* mergeLL(struct node* ptr1, struct node* ptr2){
    struct node* ptr=NULL;
    if (ptr1 == NULL){
        return ptr2;
    }
    else if (ptr2 == NULL){
        return ptr1;
    }
    if(ptr1->data <= ptr2->data){
        ptr = ptr1;
        ptr->next = mergeLL(ptr1->next,ptr2);
    }
    else{
        ptr = ptr2;
        ptr->next = mergeLL(ptr1,ptr2->next); 
    }
    return ptr;    
}

struct node *MergeSort(struct node *HEAD){
    if (HEAD == NULL)
        return (HEAD);
    else if (HEAD->next == NULL)
        return (HEAD);
    else
    {
        struct node *mid = midLL(HEAD);
        struct node *head1, *head2;
        head2 = mid->next;
        mid->next = NULL;
        head1 = MergeSort(HEAD);
        head2 = MergeSort(head2);
        head1 = mergeLL(head1, head2);
        return head1;
    }
}



int main(){
    struct node* HEAD=NULL;
    HEAD = addNode(HEAD,35);
    addNode(HEAD,60);
    addNode(HEAD,14);
    addNode(HEAD,74);
    addNode(HEAD,51);
    addNode(HEAD,99);
    addNode(HEAD,16);
    addNode(HEAD,25);
    dispLL(HEAD);

    HEAD = MergeSort(HEAD);
    dispLL(HEAD);

}