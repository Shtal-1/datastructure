// Stack in C using Specific Programming.
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

void Push(PPNODE Head, int iNO)
{
    PNODE newn = NULL;

    newn  = (PNODE)malloc(sizeof(NODE));

    newn -> data = iNO;
    newn -> next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> next = *Head;

        *Head = newn;
    }
    iCount++;
}

void Pop(PPNODE Head)
{
    PNODE temp = NULL;
    int No = 0;

    if(*Head == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }
    else
    {
        temp = *Head;

        No = (*Head) -> data;

        *Head = temp -> next;

        free(temp);

       iCount--;
        printf("\nRemoved Element is: %d\n",No);
    }
}

void Display(PNODE Head)
{
    printf("\nElements from Stack are: \n");
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

    Push(&First,101);
    Push(&First,51);
    Push(&First,31);
    Push(&First,21);
    Push(&First,11);
    Display(First);
    iRet = Count(First);
    printf("Nodes in Stacks are: %d",iRet);

    Pop(&First);
    Pop(&First);
    Pop(&First);
    Pop(&First);
    Display(First);
    iRet = Count(First);
    printf("Nodes in Stacks are: %d",iRet);

    Pop(&First);
    Pop(&First);
    Display(First);
    iRet = Count(First);
    printf("Nodes in Stacks are: %d",iRet);

    Pop(&First);
    Display(First);
    iRet = Count(First);
    printf("Nodes in Stacks are: %d",iRet);


    return 0;
}