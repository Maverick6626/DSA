// Creating circular linked list in C

#include <stdio.h>
#include <stdlib.h>

struct Node
    {
        int data;
        struct Node *next;
    };

void linkedListTraversal(struct Node *last)
{
    struct Node* ptr = last->next;
    do
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    }
    while(ptr != last->next);
}

struct Node* search(struct Node* head, struct Node* last, int data)
{
    if(head->next==head)
    {
        printf("Empty list");
        return NULL;
    }
    struct Node* ptr = last->next;
    do
    {
        if(ptr->next->data==data)
        {
            return ptr->next;
        }
        ptr = ptr->next;
    } 
    while(ptr->next!=last->next);   
    return NULL;
}


int main(void) {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* last;

    //dynamic memory allocation
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    last = (struct Node*) malloc(sizeof(struct Node));
    struct Node* ptr;

    //link first and second Node
    head->data = 7;
    head->next = second;

    //link second and third Node
    second->data = 11;
    second->next = third;

    //link third and last Node
    third->data = 41;
    third->next = last;

    //terminate list
    last->data = 66;
    last->next = head;

    printf("\nLinked List\n");
    linkedListTraversal(last);
    ptr=search(head,last,44);
    if(ptr!=NULL)
    {
        printf("\n%d\n",ptr->data);
    }
    else
    {
        printf("Element not found");
    }
}