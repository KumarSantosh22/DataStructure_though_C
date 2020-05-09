/*               Singly Linked List                 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *link;
}node;

//global variables
node *root = NULL;
int len;

int length(void)
{
    node *ptr = root;
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    return count;
}

void append(void)
{
    node *temp = (node*)malloc(sizeof(node));
    printf("Enter node data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node *ptr = root;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link=temp;
    }
}

void insert_begin(void)
{
    node *temp = (node*)malloc(sizeof(node));
    printf("Enter node data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root == NULL)
    {
        root = temp;
    } else
    {
        temp->link=root;    //right connection first
        root=temp;      //then left connection
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
        printf("INVALID LOCATION ! \n List has currently %d nodes.",len);
    } else
    {
        ptr = root;
        while(i<loc)
        {
            ptr = ptr->link;
            i++;
        }
        temp = (node*)malloc(sizeof(node));
        printf("Insert node data : ");
        scanf("%d",&temp->data);
        temp->link=NULL;
        //main logic
        temp->link=ptr->link;
        ptr->link=temp;
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
            ptr = ptr->link;
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
        printf("INVALID LOCATION !");
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link=NULL;
        free(temp);
    } else
    {
        node *p=root, *q;
        int i = 1;
        while(i<loc-1)
        {
            p = p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
        q->link=NULL;
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