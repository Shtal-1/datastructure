// Singly Linear LinkedList in C.
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

void InsertFirst(PPNODE Head, int iNO)
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
}

void InsertLast(PPNODE Head, int iNO)
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
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = NULL;

    if(*Head == NULL)
    {
        printf("Linkedlist is empty");
        return;
    }
    else
    {
        temp = *Head;

        *Head = temp -> next;

        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = NULL;

    if((*Head) == NULL)
    {
        printf("Linkedlist is empty");
        return;
    }
    else if((*Head) -> next == NULL)
    {
        free(*Head);
        (*Head) = NULL;
    }
    else
    {
        temp = *Head;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

void Display(PNODE Head)
{
    printf("\nElements from linked list are: \n");
    while(Head != NULL)
    {
    printf("|%d| ->", Head -> data);
    Head = Head -> next;
    }
    printf(" NULL\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;

    while(Head != NULL)
    {
        iCnt++;
        Head = Head -> next;
    }
    return iCnt;
}


void InsertAtPos(PPNODE Head, int iNo, int Pos)
{
    int size = 0;
    size = Count(*Head);

    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;

    if((Pos < 1) || (Pos > (size+1)))
    {
        printf("Invalid NODE position");
        return;
    }

   if(Pos == 1)
    {
        InsertFirst(Head,iNo);
    }
    else if(Pos == (size+1))
    {
        InsertLast(Head, iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = iNo;
        newn -> next = NULL;

        temp = *Head;

        for(iCnt = 1; iCnt < (Pos-1); iCnt++)
        {
           temp = temp -> next;
        }
         newn -> next = temp -> next;
         temp -> next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int Pos)
{
    int size = 0;
    size = Count(*Head);

    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;
    PNODE tempDelete = NULL;

    if((Pos < 1) || (Pos > (size+1)))
    {
        printf("Invalid NODE position");
        return;
    }

   if(Pos == 1)
    {
        DeleteFirst(Head);
    }
    else if(Pos == (size))
    {
       DeleteLast(Head);
    }
    else
    {
        temp = *Head;

        for(iCnt = 1; iCnt < (Pos-1); iCnt++)
        {
           temp = temp -> next;
        }
         tempDelete = temp -> next;
         temp -> next = temp -> next -> next;
         free( tempDelete);
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 21);
    InsertFirst(&First, 51);
    InsertFirst(&First, 101);
    InsertFirst(&First, 111);

    Display(First);
    iRet = Count(First);
    printf("\nNumber of elements from linkedlist are: %d\n",iRet);

    InsertLast(&First,11);
    InsertLast(&First,10);

    Display(First);
    iRet = Count(First);
    printf("\nNumber of elements from linkedlist are: %d\n",iRet);

    DeleteFirst(&First);

    Display(First);
    iRet = Count(First);
    printf("\nNumber of elements from linkedlist are: %d\n",iRet);

    DeleteLast(&First);

    Display(First);
    iRet = Count(First);
    printf("\nNumber of elements from linkedlist are: %d\n",iRet);

    InsertAtPos(&First, 81, 3);
    Display(First);
    iRet = Count(First);
    printf("\nNumber of elements from linkedlist are: %d\n",iRet);

    DeleteAtPos(&First, 3);
    Display(First);
    iRet = Count(First);
    printf("\nNumber of elements from linkedlist are: %d\n",iRet);

    return 0;
}