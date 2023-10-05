// Insertion doubly linked list in C
// insert at beginning O(1)
//insert in between O(n)
//insert at end O(n)
//insert in between O(1)

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

struct Node* insertAtFirst(struct Node* head, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->right = head;
    ptr->data = data; 
    return ptr;
}

struct Node* insertAtIndex(struct Node* head, int data, int index)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i=0;
    while(i!=index-1)
    {
        p = p->right;
        i++;
    }
    ptr->data = data;
    ptr->right= p->right;
    p->right = ptr;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    while(p->right!=NULL)
    {
        p = p->right;
    }
    ptr->data = data;
    ptr->right= NULL;
    p->right = ptr;
    return head;
}

struct Node* insertAfter(struct Node* head ,struct Node* prev, int data)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->right = prev->right;
    prev->right=ptr;
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

    printf("\nLinked list before insertion\n");
    linkedListTraversal(head);
    printf("\nLinked list after insertion\n");
    //head = insertAtFirst(head,56);
    //head = insertAtIndex(head,56,1);
    //head = insertAtEnd(head,56);
    //head = insertAfter(head,second,56);
    linkedListTraversal(head);


}