#include<iostream>
using namespace std;

template<class T>
struct node{
    T data;
    struct node*next;
};

template<class T>
class SLL
{
    private :
        struct node<T> *Head;
        int Length;
    
    public:
        SLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(int , T);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
SLL<T>:: SLL()
{
    Head = NULL;
    Length = 0;
}

template<class T>
void SLL<T>::InsertFirst(T No)
{
    struct node<T> *NewN = NULL;
    NewN = new node<T>;

    NewN->data = No;
    NewN->next = Head;

    Head = NewN;
    Length++;
}

template<class T>
void SLL<T>::InsertLast(T No)
{
    struct node<T> *NewN = NULL;
    struct node<T> *Temp = Head;

    NewN = new node<T>;

    NewN->data = No;
    NewN->next = NULL;

    if(Head == NULL)
    {
        Head = NewN;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = NewN;
    }
    Length++;
}

template<class T>
void SLL<T>::InsertAtPos(int iPos , T No)
{
    if(iPos < 1 || iPos > Length+1)
    {
        cout<<"Invalid Position"<<endl;
        return ;
    }

    struct node<T> *NewN = NULL;
    NewN = new node<T>;
    
    NewN->data = No;
    NewN->next = NULL;

    if(Length == 1)
    {
        NewN->next = Head;
        Head = NewN;
    }
    else
    {
        struct node<T> *Temp = Head;

        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            Temp = Temp->next;
        }

        NewN->next = Temp->next;
        Temp->next = NewN;
    }
    Length++;
}

template<class T>
void SLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return ;
    }
    struct node<T> *Temp = Head;
    
    Head = Head->next;
    delete Temp;
    Length--;
}

template<class T>
void SLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }

    struct node<T> *Temp = Head;

    while(Temp->next->next != NULL)
    {
        Temp = Temp->next;
    }

    delete Temp->next;
    Temp->next = NULL;
    Length--;
}

template<class T>
void SLL<T>::DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > Length)
    {
        return;
    }

    struct node<T> *Temp = Head;

    if(iPos == 1)
    {
        Head = Head->next;
        delete Temp;        
    }
    else
    {
        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            Temp = Temp->next;
        }
        struct node<T> *Temp2 = Temp->next;
        Temp->next = Temp->next->next;
        delete Temp2;

    }
    Length--;
}

template<class T>
void SLL<T>::Display()
{
    struct node<T> *Temp = Head;
    while(Temp!= NULL)
    {
        cout<<"|"<<Temp->data<<"|->";
        Temp = Temp->next;
    }
    cout<<endl;
}

template<class T>
int SLL<T>::Count()
{
    return Length;
}

int main()
{
    int iChoice = 1;
    SLL <char>obj;
    char Value = '\0';
    int ipos = 0, iRet = 0;

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
                cin>>Value;
                obj.InsertFirst(Value);
                break;

             case 2:
                cout<<"Enter the value to insert"<<endl;
                cin>>Value;
                obj.InsertLast(Value);
                break;

             case 3:
                cout<<"Enter the position : "<<endl;
                cin>>ipos;
                cout<<"Enter the value to insert"<<endl;
                cin>>Value;
                obj.InsertAtPos(ipos,Value);
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
        }
    }

    return 0;
}