#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *link;
}node;

node *front=NULL;
node *rear=NULL;

void Enqueue(int data)
{
     node *ptr=(node*)malloc(sizeof(node));
     ptr->data = data;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;    
            front -> link = NULL;  
            rear -> link = NULL;  
        }
        else
        {
            rear -> link = ptr;  
            rear = ptr;  
            rear->link = NULL;  
        }      
}

int Dequeue(void)
{
     int data=0;
     node *ptr=(node*)malloc(sizeof(node));
        if (front == NULL)
        {
            return data;
        }
        else
        {
            ptr = front; 
            data=ptr->data; 
            front = front -> link;  
            free(ptr);  
        }
    return data;
}

void display(void)
{        
    if(front == NULL)  
    {  
        printf("Queue is empty!\n");  
    }  
    else  
    { 
         node *ptr= front;
         printf("\nQueue    :   \n");
         while(ptr != NULL)   
        {  
            printf("%d   ",ptr->data);  
            ptr = ptr -> link;  
        } 
        printf("\n"); 
    }
}

int length()
{   int count=0;
    if(front == NULL)  
    {  
        printf("Queue is empty!\n");  
    }  
    else  
    { 
         node *ptr= front;
         while(ptr != NULL)   
        {  
            count++; 
            ptr = ptr -> link;  
        } 
    }
    return count;
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
            Enqueue(data);
            break;
        case 2:
            data=Dequeue();
            if(data==0)
            {
                printf("Queue is empyt!\n");
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
            printf("Length  : %d\n",length());
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