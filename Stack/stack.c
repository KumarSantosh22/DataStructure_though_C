/*      Stack Implementation using Static Array     */

#include <stdio.h>
#include <stdlib.h>
#define capacity 10

//creation of stack
int stack[capacity], top = -1;

int isFull(void)
{
    if(top == capacity-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(void)
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

//inserting elements into the stack
void push(int data)
{
    if(isFull())
    {
        printf("Stack is overflow.\n");
    }
    else
    {
        top++;
        stack[top]=data;
        printf("%d is pushed into the stack.\n",data);
    } 
}

//deleting element from the stack
int pop(void)
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        return stack[top--];
    }  
}

//return top element without deleting
void peek(void)
{
    if(isEmpty())
    {
        printf("Stack is empty \n!");
    }
    else
    {
        printf("Peeked element : %d\n",stack[top]);
    }
}

//display the elements of stack
void traverse(void)
{
    if(isEmpty())
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are : \n");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

//total number of elements in the stack
void length(void)
{
    printf("There are %d elements in the stack.\n",top+1);
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
            peek();
            break;
        
        case 4:
            length();
            break;
        
        case 5:
            traverse();
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