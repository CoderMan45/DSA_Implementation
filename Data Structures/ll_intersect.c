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

int len(struct node* HEAD){
    int c = 1;
    struct node* ptr = HEAD;
    while (ptr->next!=NULL){
        ptr=ptr->next;
        c++;
    }
    return c;

}

int intersect(int n1, int n2, struct node* head1, struct node* head2){
    int tmp;
    if (n1>n2){
        tmp = n1-n2;
        while(tmp--){
            head1=head1->next;
        }
    }
    else if (n2>n1){
        tmp = n2-n1;
        while(tmp--){
            head2=head2->next;
        }
    }
    do{
        head1=head1->next;
        head2=head2->next;
    }while(head1->data != head2->data);
    return head1->data;
}

int main(){
    struct node* HEAD1 = (struct node*)malloc(sizeof(struct node));
    struct node* HEAD2 = (struct node*)malloc(sizeof(struct node));
    HEAD1 = NULL; HEAD2 = NULL;
    HEAD1 = mkNode(HEAD1,15);
    mkNode(HEAD1,45);
    mkNode(HEAD1,50);
    mkNode(HEAD1,61);
    mkNode(HEAD1,13);
    mkNode(HEAD1,74);
    display(HEAD1);
    printf("\n");
    HEAD2 = mkNode(HEAD2,25);
    mkNode(HEAD2,35);
    mkNode(HEAD2,10);
    mkNode(HEAD2,30);
    mkNode(HEAD2,77);
    mkNode(HEAD2,20);
    mkNode(HEAD2,61);
    mkNode(HEAD2,13);
    mkNode(HEAD2,74);
    display(HEAD2);
    printf("\n");

    int l1 = len(HEAD1);
    int l2 = len(HEAD2);

    int num = intersect(l1,l2,HEAD1,HEAD2);
    printf("%d ",num);

}





