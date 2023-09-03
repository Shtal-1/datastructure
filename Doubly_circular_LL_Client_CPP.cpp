//Doubly circular linkedlist (C++) - menu Driven Application
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
    int iChoice = 1;
    DoublyCLL obj;
    int iValue = 0, ipos = 0, iRet = 0;

    while(iChoice != 0)
    {
        cout<<"Enter your choice : "<<endl;
        cout<<"1 : Insert First"<<endl;
        cout<<"2 : Insert Last"<<endl;
        cout<<"3 : Insert at position"<<endl;
        cout<<"4 : Delete First"<<endl;
        cout<<"5 : Delete Last"<<endl;
        cout<<"6 : Delete at position"<<endl;
        cout<<"7 : Display the data"<<endl;
        cout<<"8 : Count number of elements"<<endl;
        cout<<"9 : Terminate the application"<<endl;
        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the value to insert"<<endl;
                cin>>iValue;
                obj.InsertFirst(iValue);
                break;

            case 2:
                cout<<"Enter the value to insert"<<endl;
                cin>>iValue;
                obj.InsertLast(iValue);
                break;

            case 3:
                cout<<"Enter the value to insert"<<endl;
                cin>>iValue;
                cout<<"Enter the position : "<<endl;
                cin>>ipos;
                obj.InsertAtPos(iValue,ipos);
                break;

            case 4:
                obj.DeleteFirst();
               break;

           case 5:
                obj.DeleteLast();
               break;

            case 6:
                cout<<"Enter the position : "<<endl;
                cin>>ipos;
                obj.DeleteAtPos(ipos);
                break;

            case 7:
                obj.Display();
                break;

            case 8:
                iRet = obj.Count();
                cout<<"Number of elements are : "<<iRet<<endl;
                break;

            case 9:
                cout<<"Thank you for using the application"<<endl;
                iChoice = 0;
                break;

                default:
                    cout<<"Please enter proper choice\n";
                    break;
        }   // End of switch
    }// End of while

    return 0;
}





