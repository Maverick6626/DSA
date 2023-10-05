// Creating doubly linked list in C

#include <stdio.h>
#include <stdlib.h>

struct Node
    {
        int data;
        struct Node *left;
        struct Node *right;
    };

void linkedListTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->right;
    }
}

struct Node* deleteFirst(struct Node* head)
{
    struct Node *ptr = head;
    head = head->right; 
    free(ptr);
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->right;
    int i=0;
    while(i!=index-1)
    {
        p = p->right;
        q = q->right;
        i++;
    }
    p->right = q->right; 
    free(q);
    return head;
}

struct Node* deleteLastNode(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->right;
    while(q->right!=NULL)
    {
        p = p->right;
        q = q->right;
    }
    p->right = NULL; 
    free(q);
    return head;
}

struct Node* deleteByValue(struct Node* head, int data)
{
    struct Node* p = head;
    struct Node* q = head->right;
    while(q->data!=data && q->right!=NULL)
    {
        p = p->right;
        q = q->right;
    }
    if(q->data==data)
    {
        p->right = q->right; 
        free(q);
    }
    
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
    head->left = NULL;
    head->right = second;

    //link second and third Node
    second->data = 11;
    second->left = head;
    second->right = third;

    //link third and fourth Node
    third->data = 41;
    third->left = second;
    third->right = fourth;

    //terminate list
    fourth->data = 66;
    fourth->left = third;
    fourth->right = NULL;

    printf("\nLinked list before deletion\n");
    linkedListTraversal(head);
    printf("\nLinked list after deletion\n");
    //head = deleteFirst(head);
    //head = deleteAtIndex(head,2);
    //head = deleteLastNode(head);
    head = deleteByValue(head,41);
    linkedListTraversal(head);



}