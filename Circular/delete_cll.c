// Deletion circular linked list in C
// Delete first node
//Delete node at index
//Delete last node
//Delete node with given value

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

struct Node* deleteFirst(struct Node* last)
{
    struct Node *ptr = last->next;
    last->next = last->next->next; 
    free(ptr);
    return last;
}

struct Node* deleteAtIndex(struct Node* last, int index)
{
    struct Node* p = last->next;
    struct Node* q = last->next->next;
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next; 
    free(q);
    return last;
}

struct Node* deleteLastNode(struct Node* last)
{
    struct Node* p = last->next;
    struct Node* q = last->next->next;
    while(q->next!=last->next)
    {
        p = p->next;
        q = q->next;
    }
    p->next = last->next; 
    free(q);
    return p;
}

struct Node* deleteByValue(struct Node* last, int data)
{
    struct Node* p = last->next;
    struct Node* q = last->next->next;
    while(q->data!=data && q->next!=last->next)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data==data)
    {
        p->next = q->next; 
        free(q);
    }
    
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

    printf("\nLinked list before deletion\n");
    linkedListTraversal(last);
    printf("\nLinked list after deletion\n");
    //last = deleteFirst(last);
    //last = deleteAtIndex(last,2);
    //last = deleteLastNode(last);
    last = deleteByValue(last,11);
    linkedListTraversal(last);


}