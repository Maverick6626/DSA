// Deletion linear linked list in C
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

void linkedListTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* deleteFirst(struct Node* head)
{
    struct Node *ptr = head;
    head = head->next; 
    free(ptr);
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->next;
    int i=0;
    while(i!=index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next; 
    free(q);
    return head;
}

struct Node* deleteLastNode(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next; 
    free(q);
    return head;
}

struct Node* deleteValue(struct Node* head, int data)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->data!=data)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next; 
    free(q);
    return head;
}

int main(void) {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    //dynamic memory allocation
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    //link first and second Node
    head->data = 7;
    head->next = second;

    //link second and third Node
    second->data = 11;
    second->next = third;

    //link third and fourth Node
    third->data = 41;
    third->next = fourth;

    //terminate list
    fourth->data = 66;
    fourth->next = NULL;

    printf("\nLinked list before deletion\n");
    linkedListTraversal(head);
    printf("\nLinked list after deletion\n");
    //head = deleteFirst(head);
    //head = deleteAtIndex(head,2);
    //head = deleteLastNode(head);
    head = deleteValue(head,41);
    linkedListTraversal(head);


}