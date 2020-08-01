#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree
{
    struct binaryTree *left;
    int data;
    struct binaryTree *right;
}node;

node *root=NULL;

node* Create()
{
    int data;
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nEnter data (-1 for no node) : ");
    scanf("%d",&data);
    if (data==-1)
    {
        return 0;
    }
    ptr->data=data;
    printf("\nEnter left child of node %d   : ",data);
    ptr->left=Create();
    printf("\nEnter right child of node %d   : ",data);
    ptr->right=Create();
    return ptr;
}

void traverse_inorder(node *ptr)
{
    printf("Tree Data   :   ");
    if (ptr->left)
    {
        traverse_inorder(ptr->left);
    }
    printf("%d  ",ptr->data);
    if (ptr->right)
    {
        traverse_inorder(ptr->right);
    }
}

void main()
{
    root=Create();
    traverse_inorder(root);
}