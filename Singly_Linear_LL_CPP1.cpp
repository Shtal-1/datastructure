#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int Data;
    struct node* Next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class Singly_linkedList
{
    private:
        PNODE Head;    // Characteristics

    public:                             // Function Declaration(10)
        Singly_linkedList();
        ~Singly_linkedList();
        BOOL InsertFirst(int);
        BOOL InsertLast(int);
        BOOL InsertAtPosition(int,int);
        inline void Display();
        inline int Count();
        BOOL DeleteFirst();
        BOOL DeleteAtPosition(int);
        BOOL DeleteLast();
};

Singly_linkedList :: Singly_linkedList()
{
    Head = NULL;
}

Singly_linkedList :: ~Singly_linkedList()
{
    PNODE Temp,Navigate;

    if(Head != NULL)
    {
        Navigate = Head;

        while(Navigate != NULL)
        {
            Temp = Navigate -> Next;
            delete Navigate;
            Navigate = Temp;
        }
    }
}

BOOL Singly_linkedList :: InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    if(newn == NULL)
    {
        return FALSE;
    }

    newn -> Data = no;
    newn -> Next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> Next = Head;
        Head = newn;
    }
    return TRUE;
}

BOOL Singly_linkedList :: InsertLast(int no)
{
    PNODE newn = NULL, Temp = Head;

    newn = new NODE;
    if(newn == NULL)  // means newn(node) has no memory
    {
        return FALSE;
    }
    newn -> Data = no;
    newn -> Next = NULL;

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
    }
     return TRUE;
}

BOOL Singly_linkedList :: InsertAtPosition(int pos, int no)
{
    if((Head == NULL) || (pos > Count()+1) ||(pos <= 0))
    {
        return FALSE;
    }
    if(pos == 1)
    {
        return (InsertFirst(no));
    }
    else if(pos == (Count())+1)
    {
        return InsertLast(no);
    }
    else
    {
        PNODE newn = NULL;
        PNODE Temp = Head;
        newn = new NODE;
        if(newn == NULL)
        {
            return FALSE;
        }
        newn -> Data = no;
        newn -> Next = NULL;

        for(int i = 1; i <= (pos-2); i++)
        {
            Temp = Temp -> Next;
        }
        newn -> Next = Temp -> Next;
        Temp -> Next = newn;
    }
    return TRUE;
}

BOOL Singly_linkedList :: DeleteFirst()
{
    PNODE Temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head -> Next;
        delete(Temp);
    }
    return TRUE;
}

BOOL Singly_linkedList :: DeleteLast()
{
    if(Head == NULL)
    {
        return FALSE;
    }
    if(Head -> Next == NULL)
    {
        delete Head;
        Head == NULL;
    }
    else
    {
        PNODE Temp1 = Head, Temp2 = NULL;

        while(Temp1 -> Next -> Next != NULL)
        {
            Temp1 = Temp1 -> Next;
        }
        Temp2 = Temp1 -> Next;
        Temp1 -> Next = NULL;
        delete Temp2;
    }
    return TRUE;
}

BOOL Singly_linkedList :: DeleteAtPosition(int pos)
{
    if((Head == NULL) || (pos > Count()) ||(pos <= 0))
    {
        return FALSE;
    }
    if(pos == 1)
    {
        return (DeleteFirst());
    }
    else if(pos == Count())
    {
        return DeleteLast();
    }
    else
    {

        PNODE Temp1 = Head, Temp2 = NULL;

        for(int i = 1; i <= (pos-2); i++)
        {
            Temp1 = Temp1 -> Next;
           // ++i;
        }
        Temp2 = Temp1 -> Next;
         Temp1 -> Next = Temp2 ->Next;

         delete Temp2;
    }
    return TRUE;
}

void Singly_linkedList :: Display()
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

int Singly_linkedList :: Count()
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
    Singly_linkedList obj1;  // Static object
    Singly_linkedList *obj2 = new Singly_linkedList();  // Dynamic memory

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();

    cout<<"\nNumber of Nodes : "<< obj1.Count()<<"\n";

     obj1.InsertFirst(101);
     obj1.InsertFirst(111);

     obj1.Display();

    cout<<"\nNumber of Nodes : "<< obj1.Count()<<"\n";

    obj1.InsertAtPosition(75,4);

     obj1.Display();

    cout<<"\nNumber of Nodes : "<< obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.Display();

     obj1.DeleteLast();
     obj1.Display();

         obj2 -> InsertFirst(51);
    obj2 -> InsertFirst(21);
    obj2 -> InsertFirst(11);

    obj2 -> Display();

    obj2 -> InsertLast(551);
    obj2 -> InsertAtPosition(601,3);

    obj2 -> Display();

     cout<<"\nNumber of Nodes : "<< obj2 -> Count()<<"\n";

     delete obj2;

    return 0;
}




