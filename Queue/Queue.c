/*      Static Implementation of Queue      */
#include <stdio.h>
#include <stdlib.h>
#define size 5

int Queue[size];
int const front=0;
int rear=-1;

int isEmpty(void)
{
    if(front>rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

int isFull(void)
{
    if(rear==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

void insert(int data)
{
    if (isFull())
    {
        printf("Queue is full.\n");
    }
    else
    {
        Queue[++rear]=data;
    }    
}

int delete(void)
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        int i, data;
        data = Queue[front];
        for(i=0; i<rear; i++)
        {
            Queue[i]=Queue[i+1];
            
        }
        rear-=1;
        return data;        
    }    
}

void display(void)
{
    if(isEmpty())
    {
        printf("Queue is empty !\n");
    }
    else
    {
        printf("Queue elements : ");
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ",Queue[i]);
        }       
    }    
}

void length()
{
    printf("There are %d elements in the queue.\n",rear+1);
}

void main()
{
    int choice, data;
    while(1)
    {
        printf("\nQueue Operations : \n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Length\n");
        printf("5.Quit\n");

        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            insert(data);
            break;
        case 2:
            data=delete();
            if(isEmpty()==1)
            {
                printf("Queue is empty !\n");
            }
            else
            {
                printf("%d is deleted from queue.\n",data);
            }           
            break;
        case 3:
            display();
            break;
        case 4:
            length();
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
