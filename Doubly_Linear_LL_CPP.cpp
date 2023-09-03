// Doubly Linear LinlkedList in C++.
#include<iostream>

using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int Data;
    struct node* Next;
    struct node* Prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class Doubly_linkedList
{
    private:
        PNODE Head = NULL;

    public:
        Doubly_linkedList();
        ~Doubly_linkedList();
        BOOL InsertFirst(int);
        BOOL InsertLast(int);
        BOOL InsertAtPosition(int,int);
        inline void Display();
        inline int Count();
        BOOL DeleteFirst();
        BOOL DeleteAtPosition(int);
        BOOL DeleteLast();
};

Doubly_linkedList :: Doubly_linkedList()
{
    Head = NULL;
}

Doubly_linkedList :: ~Doubly_linkedList()
{
    PNODE Temp = Head;

    if(Head != NULL)
    {
        while(Head != NULL)
        {
            Head = Head -> Next;
            delete Temp;
            Temp = Head;
        }
    }
}

 BOOL Doubly_linkedList :: InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    if(newn == NULL)
    {
        return FALSE;
    }

    newn -> Data = no;
    newn -> Next = NULL;
    newn -> Prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> Next = Head;
        Head -> Prev = newn;
        Head = newn;
    }
    return TRUE;
}

 BOOL Doubly_linkedList :: InsertLast(int no)
 {
    PNODE newn = NULL, Temp = Head;

    newn = new NODE;

    if(newn == NULL)
    {
        return FALSE;
    }

    newn -> Data = no;
    newn -> Next = NULL;
    newn -> Prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = newn;
        newn -> Prev = Temp;
    }
    return TRUE;
 }

BOOL Doubly_linkedList :: InsertAtPosition( int no,int pos)
{
    if((Head == NULL) || (pos > Count()+1) || (pos <= 0))
    {
        return FALSE;
    }
    if(pos ==1 )
    {
        return(InsertFirst(no));
    }
    else if(pos == Count()+1)
    {
        return(InsertLast(no));
    }
    else
    {
        PNODE newn = NULL, Temp = Head;

        newn = new NODE;

        if(newn == NULL)
        {
            return FALSE;
        }

        newn -> Data = no;
        newn -> Next = NULL;
        newn -> Prev = NULL;

        for(int i = 1; i <= (pos-2); i++)
        {
            Temp = Temp -> Next;
        }
        newn -> Next = Temp -> Next;
        Temp -> Next -> Prev = newn;
        newn -> Prev = Temp;
        Temp -> Next = newn;
    }
    return TRUE;
}

BOOL Doubly_linkedList :: DeleteFirst()
{
    PNODE Temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head -> Next;
        Head -> Prev = NULL;

        delete Temp;
    }
    return TRUE;
}

BOOL Doubly_linkedList :: DeleteLast()
{
    PNODE Temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
   if(Head -> Next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        while((Temp -> Next) != NULL)  // while(Temp1 -> Next -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
                                        //Temp2 = Temp1 -> Next;
        Temp -> Prev -> Next = NULL;   // Temp1 -> Next = NULL;
        delete Temp;                   // delete Temp2;
    }
    return TRUE;
}


BOOL Doubly_linkedList :: DeleteAtPosition(int pos)
{
    if((Head == NULL) || (pos > Count()) || (pos <= 0))
    {
        return FALSE;
    }
    if(pos ==1 )
    {
        return(DeleteFirst());
    }
    else if(pos == Count()+1)
    {
        return(DeleteLast());
    }
    else
    {
        PNODE Temp = Head;

        for(int i = 1; i <= (pos-2); i++)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = Temp -> Next -> Next;
        delete (Temp -> Next -> Prev);
        Temp -> Next -> Prev = Temp;
    }
    return TRUE;
}

void Doubly_linkedList :: Display()
{
    PNODE Temp = Head;
    cout<<"\nList of Nodes are:\n";
    while(Temp != NULL)
    {
        cout<<Temp-> Data<< "->";
        Temp = Temp -> Next;
    }
    cout<< "NULL\n";
}

int Doubly_linkedList :: Count()
{
    PNODE Temp = Head;
    int iCnt = 0;

    while(Temp != NULL)
    {
        iCnt++;
        Temp = Temp -> Next;
    }
    return iCnt;
}

int main()
{
    Doubly_linkedList obj1;  // Static object
    Doubly_linkedList *obj2 = new Doubly_linkedList();  // Dynamic memory

// Function call by Static object
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();

    cout<<"\nNumber of Nodes : "<< obj1.Count()<<"\n";

     obj1.InsertFirst(101);
     obj1.InsertFirst(111);

     obj1.Display();

    cout<<"\nNumber of Nodes : "<< obj1.Count()<<"\n";

    obj1.InsertAtPosition(75,4);
    obj1.InsertAtPosition(85,4);

     obj1.Display();

    cout<<"\nNumber of Nodes : "<< obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.Display();

     obj1.DeleteLast();
     obj1.Display();

// Function call by Pointer
    obj2 -> InsertFirst(501);
    obj2 -> InsertFirst(511);
    obj2 -> InsertFirst(521);

    obj2 -> Display();

    obj2 -> InsertLast(551);
    obj2 -> InsertAtPosition(601,3);

    obj2 -> Display();

     cout<<"\nNumber of Nodes : "<< obj2 -> Count()<<"\n";

     delete obj2;
}







