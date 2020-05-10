/*              Doubly Linked List                 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
}node;

//global variables
node *root = NULL;
int len;

int length(void)
{
    node *ptr=root;
    int count=0;
    while (ptr!=NULL)
    {
        count++;
        ptr=ptr->right;
    }
    return count;
}

void append(void)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    printf("Enter node data : ");
    scanf("%d",&temp->data);
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }else
    {
        node *ptr=root;
        while(ptr->right!=NULL)
        {
            ptr=ptr->right;
        }
        ptr->right=temp;
        temp->left=ptr;
    }
}

void insert_begin(void)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->left=NULL;
    printf("\nEnter node data : ");
    scanf("%d",&temp->data);
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }else
    {
        temp->right=root;
        root->left=temp;
        root=temp;
    }
}

void insert_at_position(void)
{
    node *ptr, *temp;
    int i = 1, loc;
    printf("Enter the location : ");
    scanf("%d",&loc);
    if (loc > length())
    {
        printf("INVALID LOCATION ! \n List has currently %d nodes.",length());
    } else
    {
        ptr = root;
        while(i<loc)
        {
            ptr = ptr->right;
            i++;
        }
        temp = (node*)malloc(sizeof(node));
        temp->left=NULL;
        printf("Insert node data : ");
        scanf("%d",&temp->data);
        temp->right=NULL;
        //main logic
        temp->right=ptr->right;
        ptr->right->left=temp;
        temp->left=ptr;
        ptr->right=temp;
    }
}

void display()
{
    node *ptr = root;
    if (ptr == NULL)
    {
        printf("List is empty.\n");
    } else
    {
        while (ptr != NULL)
        {
            printf("%d -> ",ptr->data);
            ptr = ptr->right;
        }
        printf("\n");
    }
}

void delete()
{
    node *temp;
    int loc;
    printf("Which node you want to delete ? ");
    scanf("%d",&loc);
    if (loc>length())
    {
        printf("INVALID LOCATION !\n");
        printf("List is having currently %d nodes.\n",length());
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->right;
        root->left=NULL;
        temp->right=NULL;
        free(temp);
    }
    else
    {
        node *p=root, *q;
        int i = 1;
        while(i<loc-1)
        {
            p = p->right;
            i++;
        }
        q=p->right;
        p->right->left=p;
        p->right=q->right;
        q->left=NULL;
        q->right=NULL;
        free(q);
    }
}

void main()
{
    while (1)
    {
        int choice;
        printf("\nSingly linked list operations : \n");
        printf("1.Append\n");
        printf("2.Insert node in the begining\n");
        printf("3.Insert node at the specified position\n");
        printf("4.Calculate total nodes\n");
        printf("5.Display data\n");
        printf("6.Delete\n");
        printf("7.Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1 : append();
                break;
            case 2 : insert_begin();
                break;
            case 3 : insert_at_position();
                break;
            case 4 : len = length();
                printf("Length : %d\n",len);
                break;
            case 5 : display();
                break;
            case 6 : delete();
                break;
            case 7 : exit(0);
                break;
            default: printf("INVALID SELECTION !");
        }
    }
}
