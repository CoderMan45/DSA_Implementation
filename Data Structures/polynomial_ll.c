#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node *next;
};

struct node *mkNode(struct node *ptr, int coef, int pow)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->coeff = coef;
        ptr->power = pow;
        ptr->next = NULL;
        return ptr;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = (struct node *)malloc(sizeof(struct node));
    ptr = ptr->next;
    ptr->coeff = coef;
    ptr->power = pow;
    ptr->next = NULL;
    return NULL;
}

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%dx^%d ", ptr->coeff, ptr->power);
        ptr = ptr->next;
    }
    printf("\n");
}

void add_poly(struct node *ptr1, struct node *ptr2)
{
    do
    {
        if (ptr1->power > ptr2->power || ptr2 == NULL)
        {
            printf("%dx^%d ", ptr1->coeff, ptr1->power);
            if (ptr1->next != NULL)
                ptr1 = ptr1->next;
            else
                ptr1 == NULL;
        }
        else if (ptr2->power > ptr1->power || ptr1 == NULL)
        {
            printf("%dx^%d ", ptr2->coeff, ptr2->power);
            if (ptr2->next != NULL)
                ptr2 = ptr2->next;
            else
                ptr2 == NULL;
        }
        else
        {
            printf("%dx^%d ", ptr2->coeff + ptr1->coeff, ptr2->power + ptr1->power);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    } while (ptr1 != NULL || ptr2 != NULL);
}

int main()
{
    struct node *pol1 = NULL;
    struct node *pol2 = NULL;
    pol1 = mkNode(pol1, 5, 3);
    mkNode(pol1, 25, 2);
    mkNode(pol1, 30, 1);
    mkNode(pol1, 50, 0);
    display(pol1);
    pol2 = mkNode(pol2, 23, 5);
    mkNode(pol2, 70, 2);
    mkNode(pol2, 29, 1);
    mkNode(pol2, 20, 0);
    display(pol2);
    add_poly(pol1, pol2);
}