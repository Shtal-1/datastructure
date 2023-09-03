// Doubly circular linkedlist (C++)
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node* prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class DoublyCLL
{
    private:        // characteristics
        PNODE Head;
        PNODE Tail;

    public:         // Behaviours
    DoublyCLL();
    void InsertFirst(int no);
    void InsertLast(int no);
    void InsertAtPos(int no, int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    void Display();
    int Count();
};

    DoublyCLL :: DoublyCLL()
     {
         Head = NULL;
         Tail = NULL;
     }

   void DoublyCLL :: InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn  = new NODE;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        if((Head == NULL) && (Tail == NULL))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Head -> prev = newn;
            newn -> next = Head;
            Head = newn;
            Head -> prev = Tail;
        }
        Tail -> next = Head;
    }

   void DoublyCLL :: InsertLast(int no)
    {
        PNODE newn = NULL;
        newn  = new NODE;

        newn -> data = no;
        newn -> next = NULL;
       newn -> prev = NULL;

        if((Head == NULL) && (Tail == NULL))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail -> next = newn;
            newn -> prev = Tail;
            Tail = newn;
            Head -> prev = Tail;
        }
        Tail -> next = Head;   // he liha garaj nasli tari karan yane farak padat nahi. common statement ahe
    }

   void DoublyCLL :: InsertAtPos(int no, int ipos)
    {
        int iSize = Count();
        if((ipos < 1) || (ipos > iSize+1))
        {
            return;
        }
        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == iSize +1)
        {
            InsertLast(no);
        }
        else
        {
          PNODE newn = NULL;
          newn  = new NODE;

          newn -> data = no;
          newn -> next = NULL;
         newn -> prev = NULL;

        PNODE temp = Head;
        int iCnt = 0;

        for(iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> prev = temp;
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        }
    }

    void DoublyCLL :: DeleteFirst()
    {
        if(Head == NULL && Tail == NULL)
        {
            return;
        }
        else if(Head == Tail)
        {
            delete Head;  // delete Tail;
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            Head = Head -> next;
            Head -> prev = Tail;
            delete Tail-> next;
        }
        Tail -> next = Head;
    }

    void DoublyCLL :: DeleteLast()
    {
        if(Head == NULL && Tail == NULL)
        {
            return;
        }
        else if(Head == Tail)
        {
            delete Head;  // delete Tail;
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            PNODE temp = Head;

            while(temp-> next != Tail)
             {
                temp = temp -> next;
             }
             delete temp -> next; // delete Tail;
             Tail = temp;
             Head -> prev = Tail;
        }
        Tail -> next = Head;
    }

    void DoublyCLL :: DeleteAtPos(int ipos)
    {
         int iSize = Count();
        if((ipos < 1) || (ipos > iSize))
        {
            cout<<"Invalid Position";
            return;
        }
        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == iSize)
        {
            DeleteLast();
        }
        else
        {
          PNODE temp1 = Head;
          int iCnt = 0;

          for(iCnt = 1; iCnt < ipos -1; iCnt++)
          {
              temp1 = temp1 -> next;
          }
            PNODE temp2 = temp1 -> next;
            temp1 -> next = temp2 -> next;
            delete temp2;
            temp1 -> next -> prev = temp1;
        }

    }

    void DoublyCLL :: Display()
    {
        PNODE temp = Head;

        if(Head == NULL && Tail ==NULL)
        {
            return;
        }

       do
        {
            cout<<"|"<<temp-> data<<"|->";
            temp = temp -> next;
        } while(temp != Tail->next);   //(temp != Head);

        cout<<endl;
    }

    int DoublyCLL :: Count()
    {
        PNODE temp = Head;
        int iCnt = 0;

        if(Head == NULL && Tail ==NULL)
        {
            return 0;
        }

       do
        {
            iCnt++;
            temp = temp -> next;
        } while(temp != Tail->next);   //(temp != Head);

        return iCnt;
    }

int main()
    {
        int iRet = 0;
        DoublyCLL obj;

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        obj.InsertFirst(1);
        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();
        iRet = obj.Count();
        cout<<"\n number of nodes are:"<<iRet<<endl;

        obj.InsertAtPos(75,3);
        obj.Display();
        iRet = obj.Count();
        cout<<"\n number of nodes are:"<<iRet<<endl;

        obj.DeleteFirst();
        obj.Display();
        iRet = obj.Count();
        cout<<"\n number of nodes are:"<<iRet<<endl;

        obj.DeleteLast();
        obj.Display();
        iRet = obj.Count();
        cout<<"\n number of nodes are:"<<iRet<<endl;

        obj.DeleteAtPos(2);
        obj.Display();
        iRet = obj.Count();
        cout<<"\n number of nodes are:"<<iRet<<endl;

        return 0;
    }