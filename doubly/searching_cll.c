// Searching doubly linked list in C

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

struct Node* search(struct Node* head, int data)
{
    if(head==NULL)
    {
        printf("Empty list");
        return NULL;
    }
    struct Node* ptr = head;
    while(ptr->right!=NULL)
    {
        if(ptr->right->data==data)
        {
            return ptr->right;
        }
        ptr = ptr->right;
    }   
    return NULL; 
}

int main(void) 
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    struct Node* ptr;

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

    printf("\nLinked list\n");
    linkedListTraversal(head);
    ptr=search(head,66);
    if(ptr!=NULL)
    {
        printf("\n%d\n",ptr->data);
    }
    else
    {
        printf("Empty List");
    }
    

}