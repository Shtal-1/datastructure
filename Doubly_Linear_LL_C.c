// data structure doubly linear linked list.
// This is a full doubly linear linked list code.

#include<stdio.h>
#include<stdlib.h>

struct node
    {
        int data ;
        struct node *next;
        struct node *prev;         //*
    };

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE head)
{
    printf("\nData from linkedList is:\n");
    while(head != NULL)
    {
        printf("|%d| <=>", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCnt = 0;

    while(head != NULL)
    {
       iCnt++;
        head = head -> next;
    }
    return iCnt;
}

void InsertFirst(PPNODE head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev  = NULL;     //*

    if(*head == NULL)   // LL is empty
    {
        *head = newn;
    }
    else   //LL contains at-least one node
    {
        newn -> next = *head;
        (*head) -> prev = newn;   //  newn -> next -> prev = newn; (but it is complex)
        *head = newn;
    }
}

void InsertLast(PPNODE head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev  = NULL;             //*

    if(*head == NULL)   // LL is empty
    {
        *head = newn;
    }
    else   //LL contains at-least one node
    {
         temp = *head;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev  = temp;           //*    temp -> next -> prev = temp;
    }
}

void DeleteFirst(PPNODE head)
{
    if(*head == NULL)
    {
        return;
    }
    if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else     // more than one node
    {
        *head = (*head) -> next;         //*
        free((*head)-> prev);           //*
        ((*head)-> prev) = NULL;       //*
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;

    if(*head == NULL)
    {
        return;
    }
    if((*head) -> next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else     // more than one node
    {
        temp = *head;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp -> next);
        temp -> next = NULL;
    }
}

void InsertAtPos(PPNODE head, int no, int pos)
{
    PNODE temp = NULL;
    PNODE newn = NULL;
    int size = 0, iCnt = 0;
    size = Count(*head);

    if((pos < 1) || (pos > (size+1)))
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos == 1)
    {
        InsertFirst(head, no);
    }
    else if(pos == (size+1))
    {
        InsertLast(head,no);
    }
    else
    {
        temp = *head;
        newn = (PNODE)malloc(sizeof(NODE));

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev  = NULL;

        for(iCnt=1; iCnt < (pos-1); iCnt++)
        {
           temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;    //*

        temp -> next = newn;
        newn -> prev = temp;     //*
    }
}

void DeleteAtPos(PPNODE head, int pos)
{
    PNODE temp = NULL;

    int size = 0, iCnt = 0;
    size = Count(*head);

    if((pos < 1) || (pos > (size)))
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos == 1)
    {
        DeleteFirst(head);
    }
    else if(pos == (size))
    {
        DeleteLast(head);
    }
    else
    {
        temp = *head;

        for(iCnt=1; iCnt < (pos-1); iCnt++)
        {
           temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        free(temp -> next -> prev);
        temp -> next -> prev = temp;
    }
}

int main()
{
    PNODE first = NULL;
    int iRet = 0;

    InsertFirst(&first,21);
    InsertFirst(&first,11);

    InsertLast(&first,51);
    InsertLast(&first,101);

    Display(first);
    iRet = Count(first);
    printf("\nNumber of nodes are: %d\n", iRet);

    InsertAtPos(&first,75,3);
    Display(first);

    DeleteAtPos(&first,3);
    Display(first);

    DeleteFirst(&first);

    DeleteLast(&first);

    Display(first);
    iRet = Count(first);
    printf("\nNumber of nodes are: %d\n", iRet);

    return 0;
}