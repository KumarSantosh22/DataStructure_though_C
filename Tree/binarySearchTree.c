/*      Binary Search Tree using Linked List       */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
}node;

node *root=NULL;

void insert(int data)
{
    node *parent=root;
    node*temp = (node*)malloc(sizeof(node));
    temp->left=NULL;
    temp->data=data;
    temp->right=NULL;
    if (root==NULL)
    {
        root=temp;
    }
    else
    {
        node *current=root;
        while (current)
        {
            parent=current;
            if (temp->data > current->data)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }            
        }
        if (temp->data > parent->data)
        {
            parent->right=temp;
        }
        else
        {
            parent->left=temp;
        }        
    }      
}

void search(node* current, int data, node* parent)  
{  
    while (current != NULL && current->data != data)  
    {  
        parent = current;  
  
        if (data < current->data)  
            current = current->left;  
        else  
            current = current->right;  
    }  
}


void traverse_inorder(node *temp)
{
    if (temp==NULL)
    {
        printf("BST is empty!\n");
    }
    else
    {
        if (temp->left)
        {
            traverse_inorder(temp->left);
        }
        printf("%d -> ",temp->data);
        if (temp->right)
        {
            traverse_inorder(temp->right);
        } 
    }   
}

void delete(int data)
{
    node *parent=NULL;
    node *current=root;
    
    if (root==NULL)
    {
        printf("BST is empty !");
    }
    while (data!=current->data)
    {
        parent=current;
        if(data>parent->data)
        {
            current=current->right;
        }
        else
        {
            current=current->left;
        } 
    }

    if (current-data==NULL)
    {
        printf("Data not found!");
    }

    else if (current==root && (root->left==NULL && root->right==NULL))
    {
        root=NULL;
        free(current);
    }
    
    else if (current->left==NULL && current->right==NULL)
    {
         if (current==parent->left)
        {
            parent->left=NULL;
        }
        else
        {
            parent->right=NULL;
        }
        free(current);
    }
    else if (current->left!=NULL && current->right==NULL)
    {
        if (current==parent->right)
        {
            parent->right=current->left;
            current->left=NULL;
        }
        else
        {
            parent->left=current->left;
            current->right=NULL;
        }
        free(current);
    }
    else if (current->left==NULL && current->right!=NULL)
    {
        if (current==parent->right)
        {
            parent->right=current->right;
            current->left=NULL;
        }
        else
        {
            parent->left=current->right;
            current->right=NULL;
        }
        free(current);
    }
    else // if (current->left!=NULL && current->right!=NULL)
    {
        node * t1;
        t1=current->right;
        if (t1->left==NULL && t1->right==NULL)
        {
            current->data=t1->data;
            current->right=NULL;
            free(t1);
        }
        else if (t1->left==NULL && t1->right!=NULL)
        {
            current->data=t1->data;
            current->right=t1->right;
            t1->right=NULL;
            free(t1);
        }
        else
        {
             while (t1->left!=NULL)
             {
                 parent=t1;
                 t1=t1->left;
             }
             current->data=t1->data;
             if (parent->left==t1)
             {
                 parent->left=NULL;
             }
             else
             {
                 parent->right=NULL;
             }
             free(t1);
        }
    }  
}


void main()
{
    int choice, data;
    node *ptr;
    while(1)
    {
        printf("\nBinary Search Tree (BST) Operations : \n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Search\n");
        printf("5.Quit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            insert(data);
            break;
        case 2:
            printf("\nEnter the data which you want to delete   :  ");
            scanf("%d",&data);
            delete(data);      
            break;
        case 3:
            traverse_inorder(root);
            break;
        case 4:
            printf("\nEnter the data which you want to search  :  ");
            scanf("%d",&data);
            search(root,data,ptr);
            if (ptr==NULL)
            {
                printf("Data not found.");
            }
            else
            {
                printf("%d is found at location %u",data,ptr);
            }
            break;
        case 5:
            exit(0);
            break;        
        default:
            printf("\nEnter a valid choice !");
            break;
        }
    }
}