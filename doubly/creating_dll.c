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

    linkedListTraversal(head);


}