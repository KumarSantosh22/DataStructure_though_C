#include <stdio.h>
#include <stdlib.h>
#define size 50

int arr[size];
int index=-1;
int count;

void append(int count)
{
    if (index==size-1 || size==index+count)
    {
        printf("Array index out of bound !");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("Enetr data : ");
            scanf("%d",&arr[++index]);
        }
    }    
}

void display(void)
{
    if (index==-1)
    {
        printf("Array is empty !\n");
    }
    else
    {
        for (int i = 0; i <= index; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
}

void length()
{
    printf("\nSize of array : %d",size);
    printf("\nCurrently, There are  %d elements in the array.\n",index+1);
}

int delete(int loc)
{
    if (index==-1)
    {
        printf("Array is empty! Nothing to delete.");
    }
    else if (loc-1<0 || loc-1>index)
    {
        printf("Enter a valid location.");
    }
    else
    {
        for (int i=loc-1; i < index; i++)
        {
            arr[i]=arr[i+1];
        }
        index-=1;
    }   
}

void insert(int pos)
{
    if (index==size-1)
    {
        printf("Index is out of bound !\n");
    }
    else if (pos<1 || pos>size)
    {
        printf("Enter a valid location !\n");
    }
    else
    {
        int data,temp=pos-1;
        for (int i = pos-1; i < index; i++)
        {
            arr[index+1]=arr[index];
        }
        printf("Enter data : ");
        scanf("%d",&data);
        arr[temp]=data;
        index+=1; 
    }
    
    
    
}

void main()
{
    int choice, loc, pos;
    while (1)
    {
        printf("\nArray Operations : \n");
        printf("1.Append\n");
        printf("2.Insert in the begining\n");
        printf("3.Insert at specific location\n");
        printf("4.Delete\n");
        printf("5.Display\n");
        printf("6.Size and length\n");
        printf("7.Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nHow many data you want to append ? ");
            scanf("%d",&count);
            append(count);
            break;
        case 2:
            insert(1);
            break;
        case 3:
            printf("Enter the location of data where you want to insert : ");
            scanf("%d",&pos);
            insert(pos);
            break;
        case 4:
            printf("Enter the location of data which you want to delete : ");
            scanf("%d",&loc);
            delete(loc);
            break;
        case 5:
            display();
            break;
        case 6:
            length();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Enter a valid choice !");
            break;
        }
    }  
}