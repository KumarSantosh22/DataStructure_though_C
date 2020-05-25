#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *link;
}node;

node *top=NULL;

void push(int data)
{
     node *temp=(node*)malloc(sizeof(node));
     temp->data=data;
     temp->link=top;
     top=temp;
}

int pop(void)
{
    if(top==NULL)
    {
        return 0;
    }
    else
    {
        node *temp=top;
        int data=top->data;
        top=top->link;
        temp->link=NULL;
        free(temp);
        return data;
    }   
}

int peek(void)
{
    node *temp=top;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        return top->data;
    }   
}

void display(void)
{
    node *temp=top;
    if(temp==NULL)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        while (temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp=temp->link;
        }
    }
    printf("\n");
}

int length()
{
    int count=0;
    node *temp=top;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        while (temp!=NULL)
        {
            count++;
            temp=temp->link;
        }
        return count;
    }
    printf("\n");
}

void main()
{   
    int item;
    int choice;
    while (1)
    {
        printf("\nStack Operations : \n");
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Peek \n");
        printf("4.Length \n");
        printf("5.Display \n");
        printf("6.Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter data : ");
            scanf("%d",&item);
            push(item);
            break;
        
        case 2:
            item=pop();
            if(item==0)
            {
                printf("Stack is underflow.\n");
            }else
            {
                printf("%d is popped from the stack.\n",item);
            }
            break;
        
        case 3:
            item=peek();
            if(item==0)
            {
                printf("Nothing to peek ):\n");
            }else
            {
                printf("%d is peeked from the stack.\n",item);
            }
            break;
        
        case 4:
            printf("Length  : %d\n",length());
            break;
        
        case 5:
            display();
            break;
        
        case 6:
            exit(0);
            break;

        default:
            printf("Enter a valid choice !\n\n");
            break;
        }
    }   
}