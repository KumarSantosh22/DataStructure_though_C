/*      Static Implementation of Circular Queue      */
#include <stdio.h>
#include <stdlib.h>
#define size 5

int CQueue[size];
int front=-1;
int rear=-1;

void Enqueue(int data)
{
    if(front==rear+1 || (front == 0 && rear == size - 1))
    {
        printf("Queue is full !\n");
    }
    else if (front==-1 && rear==-1)
    {
        front=rear=0;
        CQueue[rear]=data;
    }
    else if (rear==size-1)
    {
        rear=0;
        CQueue[rear]=data;
    }
    else
    {
        rear++;
        CQueue[rear]=data;
    }   
}

void Dequeue(void)
{
    int data;
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty !\n");
    }
    else if (front==rear)
    {
        data=CQueue[front];
        printf("%d is deleted from queue.\n",data);
        front=rear=-1;
        
    }
    else if (front==size-1)
    {
        data=CQueue[front];
        printf("%d is deleted from queue.\n",data);
        front=0; 
    }
    else
    {
        data=CQueue[front];
        printf("%d is deleted from queue.\n",data);
        front++;
    }    
}

void display(void)
{
    int i;
    if (front ==-1 && rear == -1)
    {
        printf("Queue is empty !\n");
    }
    else 
    {
        printf("\n Front -> %d ", front);
        printf("\n Items -> ");
        for (i= front; i != rear; i=(i+1)%size) 
         {
            printf("%d ", CQueue[i]);
         }
        printf("%d ", CQueue[i]);
        printf("\n Rear -> %d \n", rear);
    }    
}

void main()
{
    int choice, data;
    while(1)
    {
        printf("\nCircular Queue Operations : \n");
        printf("1.Enqueue\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d",&data);
            Enqueue(data);
            break;
        case 2:
            Dequeue();      
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;        
        default:
            printf("\nEnter a valid choice !");
            break;
        }
    }
}