// Queue Data Structure programs in C using Specific programming.
#include<stdio.h>
#include<stdlib.h>

struct node
    {
     int data;
     struct node *next;
    };

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

int iCount = 0;

void Enqueue(PPNODE Head, int iNO)
{
     PNODE newn = NULL;
     PNODE temp = NULL;

    newn  = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNO;
    newn -> next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
       temp = *Head;

       while(temp -> next != NULL)
       {
            temp = temp -> next;
       }
       temp -> next = newn;
    }
    iCount++;
}

void Dequeue(PPNODE Head)
{
    PNODE temp = NULL;
    int No = 0;

    if(iCount == 0)
    {
        printf("\nQueue is empty\n");
        return;
    }
    else
    {
        temp = *Head;

        No = (*Head) -> data;

        *Head = temp -> next;

        free(temp);

        printf("\nRemoved Element is: %d\n",No);
    }
    iCount--;
}

void Display(PNODE Head)
{
    printf("\nElements from Queue are: \n");
    while(Head != NULL)
    {
    printf("|%d| ->", Head -> data);
    Head = Head -> next;
    }
    printf(" NULL\n");
}

int Count(PNODE Head)
{
    return iCount;
}

int main()
{
   PNODE First = NULL;
   int iRet = 0;

    Enqueue(&First,11);
    Enqueue(&First,21);
    Enqueue(&First,31);
    Enqueue(&First,41);
    Enqueue(&First,51);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are: %d\n",iRet);

    Dequeue(&First);
    Dequeue(&First);
    Dequeue(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are: %d\n",iRet);

    Dequeue(&First);
    Dequeue(&First);
    Dequeue(&First);
    Display(First);
    iRet = Count(First);
    printf("Number of nodes are: %d\n",iRet);

    return 0;
}