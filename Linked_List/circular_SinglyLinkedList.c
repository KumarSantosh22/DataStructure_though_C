/*      Circular Singly Linked List      */
#include <stdio.h>
#include <stdlib.h>
 
 typedef struct Node
 {
     int data;
     struct Node *link;
 }node;
 
 node* head=NULL;
 int len;

 int length(void)
 {
     int count=0;
    node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty.\n");
    } else
    {
        count++;
        while (ptr->link != head)
        {
            count++;
            ptr = ptr->link;
        }
    }
    return count;
}

 void append(void)
{
    node *temp = (node*)malloc(sizeof(node));
    printf("Enter node data : ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if (head == NULL)
    {
        head = temp;
        temp->link=head;
    }
    else
    {
        node *ptr = head;
        while (ptr->link != head)
        {
            ptr = ptr->link;
        }
        ptr->link=temp;
        temp->link=head;
    }
}
 
 void display()
{
    node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty.\n");
    } else
    {
        while (ptr->link != head)
        {
            printf("%d -> ",ptr->data);
            ptr = ptr->link;
        }
        printf("%d -> ",ptr->data);
        printf("\n");
    }
}

void insert_begin()
{
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nEnter data  : ");
    scanf("%d",&ptr->data);
    if (head==NULL)
    {
        head=ptr;
        ptr->link=head;
    }
    else
    {
        node *temp=head;
        while (temp->link!=head)
        {
            temp=temp->link;
        }
        temp->link=ptr;
        ptr->link=head;
        head=ptr;
    }
    printf("\n");  
}

void insert_at_position(void)
{
    int loc;
    printf("Enter location  :  ");
    scanf("%d",&loc);

    if (loc<1 || loc>length())
    {
        printf("Invalid Location !\n");
        printf("Currently, There are %d nodes in the list.\n",length());
    }
    else
    {
        node *ptr=(node*)malloc(sizeof(node));
        printf("\nEnter data  : ");
        scanf("%d",&ptr->data);
        int i=1;
        node *temp=head;
        while (i<loc-1)
        {
            temp=temp->link;
            i++;
        }
        ptr->link=temp->link;
        temp->link=ptr;
    }
    printf("\n");  
}

void delete(void)
{
    int loc;
    printf("Enter location : ");
    scanf("%d",&loc);
    if (head==NULL)
    {
        printf("List is empty! Nothong to delete.\n");
    }
    else if (loc<1 || loc>length())
    {
        printf("Invalid Location !\n");
        printf("Currently, There are %d nodes in the list.\n",length());
    }

    //deleting first node
    else if (loc==1)
    {
        if (head->link==head)
        {
            head=NULL;
            free(head);
        }
        else
        {
            node *ptr=head;
            while (ptr->link!=head)
            {
                ptr=ptr->link;
            }
            ptr->link=head->link;
            free(head);
            head=ptr->link;
        }   
    }

    //deleting last node
    else if (loc==length())
    {
         node *ptr=head;
         node *preptr;
         while (ptr->link!=head)
         {
             preptr=ptr;
             ptr=ptr->link;
         } 
         preptr->link=ptr->link;
         free(ptr);
    }  

    //deleting specific node
    else
    {
        node *ptr=head;
         node *preptr;
         int i=1;
         while (i<loc)
         {
             preptr=ptr;
             ptr=ptr->link;
             i++;
         } 
         preptr->link=ptr->link;
         free(ptr);
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
            case 4 : 
                printf("Length : %d\n",length());
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