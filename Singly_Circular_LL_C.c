// Singly Circular LinkedList in C language.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int Data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;

    newn  = (PNODE)malloc(sizeof(NODE));

    newn -> Data = iNo;
    newn -> next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        newn -> next = *Head;
        *Head = newn;
    }
    (*Tail) -> next = (*Head);
}

void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;

    newn  = (PNODE)malloc(sizeof(NODE));

    newn -> Data = iNo;
    newn -> next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }
    else
    {
        (*Tail) -> next = newn;
        *Tail = newn;
    }
    (*Tail) -> next = (*Head);
}

void Display(PNODE Head, PNODE Tail)
{
    printf("\nElements from linked list are: \n");

      if(((Head) == NULL) && ((Tail) == NULL))
    {
       return;
    }
    else
    {
        do
        {
             printf("|%d| ->", Head -> Data);
             Head = Head -> next;
        }while((Head) != (Tail -> next));
    }
    printf("NULL");
}

int Count(PNODE Head, PNODE Tail)
{
   int iCnt = 0;

    if(((Head) == NULL) && ((Tail) == NULL))
    {
         return 0;
    }
    else
    {
        do
        {
             iCnt++;
             Head = Head -> next;
        }while((Head) != (Tail -> next));
    }
        return iCnt;
}
void InsertAtPos(PPNODE Head, PPNODE Tail, int iNo, int iPos)
{
   int iSize = 0;
   iSize = Count(*Head, *Tail);

   PNODE newn = NULL;
   PNODE Temp  = *Head;
   int iCnt = 0;

    if((iPos < 1) || (iPos > (iSize+1)))
    {
        printf("Invalid NODE position");
        return;
    }

   if(iPos == 1)
    {
        InsertFirst(Head,Tail,iNo);
    }
    else if(iPos == (iSize+1))
    {
        InsertLast(Head,Tail, iNo);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> Data = iNo;
        newn -> next = NULL;

        Temp  = *Head;

       for(iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
           Temp = Temp -> next;
        }
        newn -> next = Temp -> next;
        Temp -> next = newn;
    }
}

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if((*Head) == NULL && (*Tail) == NULL)
        {
            return;
        }
        else if((*Head) == (*Tail))
        {
            free(*Head);  // delete Tail;
            (*Head) = NULL;
            (*Tail) = NULL;
        }
        else
        {
            (*Head) = (*Head) -> next;
            free((*Tail)-> next);
        }
     (*Tail) -> next = (*Head);
 }

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    if((*Head) == NULL && (*Tail) == NULL)
        {
            return;
        }
        else if((*Head) == (*Tail))
        {
            free(*Head);  // delete Tail;
            (*Head) = NULL;
            (*Tail) = NULL;
        }
        else
        {
           PNODE Temp = *Head;

           while(Temp -> next != (*Tail))
           {
            Temp = Temp -> next;
           }
            free(Temp -> next);
            (*Tail)  = Temp;
        }
     (*Tail) -> next = (*Head);
 }

 void DeleteAtPos(PPNODE Head, PPNODE Tail, int iPos)
{
   int iSize = 0;
   iSize = Count(*Head, *Tail);

   PNODE Temp1  = NULL;
   int iCnt = 0;

    if((iPos < 1) || (iPos > (iSize+1)))
    {
        printf("Invalid NODE position");
        return;
    }

   if(iPos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(iPos == (iSize))
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        Temp1  = *Head;

       for(iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
           Temp1 = Temp1 -> next;
        }
        PNODE Temp2 = Temp1 -> next;
        Temp1 -> next = Temp2 -> next;
        free(Temp2);
    }
}

int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;
    int iRet = 0;

    InsertFirst(&First, &Last, 21);
    InsertFirst(&First, &Last, 11);
    InsertFirst(&First, &Last, 10);
    Display(First, Last);
    iRet = Count(First,Last);
    printf("\nNumber of Nodes are: %d\n",iRet);

    InsertLast(&First, &Last, 51);
    InsertLast(&First, &Last, 101);
    InsertLast(&First, &Last, 111);
    InsertLast(&First, &Last, 151);
    Display(First, Last);
    iRet = Count(First,Last);
    printf("\nNumber of Nodes are: %d\n",iRet);

    InsertAtPos(&First, &Last, 71, 4);
    Display(First, Last);
    iRet = Count(First,Last);
    printf("\nNumber of Nodes are: %d\n",iRet);

    DeleteFirst(&First, &Last);
    Display(First, Last);
    iRet = Count(First,Last);
    printf("\nNumber of Nodes are: %d\n",iRet);

    DeleteLast(&First, &Last);
    Display(First, Last);
    iRet = Count(First,Last);
    printf("\nNumber of Nodes are: %d\n",iRet);

    DeleteAtPos(&First, &Last, 3);
    Display(First, Last);
    iRet = Count(First,Last);
    printf("\nNumber of Nodes are: %d\n",iRet);

    return 0;
}