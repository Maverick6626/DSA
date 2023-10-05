// Insertion circular linked list in C
// insert at beginning O(1)
//insert in between O(n)
//insert at end O(n)
//insert in between O(1)

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

struct Node* insertAtFirst(struct Node* last, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = last->next;
    ptr->data = data; 
    last->next=ptr;
    return last;
}

struct Node* insertAtIndex(struct Node* last, int data, int index)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = last->next;
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next= p->next;
    p->next = ptr;
    return last;
}

struct Node* insertAtEnd(struct Node* last, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next=last->next;
    last->next=ptr;
    return ptr;
}

struct Node* insertAfter(struct Node* last ,struct Node* prev, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prev->next;
    prev->next=ptr;
    return last;
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

    printf("\nLinked list before insertion\n");
    linkedListTraversal(last);
    printf("\nLinked list after insertion\n");
    //last = insertAtFirst(last,56);
    //last = insertAtIndex(last,56,1);
    //last = insertAtEnd(last,56);
    last = insertAfter(last,second,56);
    linkedListTraversal(last);


}