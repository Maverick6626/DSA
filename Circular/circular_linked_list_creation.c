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

    linkedListTraversal(last);


}