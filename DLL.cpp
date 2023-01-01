#include<iostream>

using namespace std;

template <class T>
struct node 
{
    T data;
    struct node<T>* next;
    struct node<T>* prev;
};

template <class T>
class DLL
{
    private:
        struct node<T>* Head;
        int Length;

    public:
        DLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(int , T);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
        T Search(int);
};

template <class T>
DLL<T>::DLL()
{
    Head = NULL;
    Length = 0;
}

template <class T>
void DLL<T>::InsertFirst(T No)
{
    struct node<T> *NewN = NULL;
    NewN = new node<T>;

    NewN->data = No;
    NewN->next = Head;
    NewN->prev = NULL;

    if(Head != NULL)
    {
        Head->prev = NewN;
    }

    Head = NewN;
    Length++;
}

template <class T>
void DLL<T>::InsertLast(T No)
{
    struct node<T> *NewN = NULL;
    struct node<T> *Temp = Head;

    NewN = new node<T>;

    NewN->data = No;
    NewN->next = NULL;
    NewN->prev = NULL;

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
        NewN->prev = Temp;
    }
    Length++;
}

template <class T>
void DLL<T>::InsertAtPos(int iPos , T No)
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
    NewN->prev = NULL;

    if(iPos == 1)
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
        NewN->prev = Temp;
        if(NewN->next != NULL)
        {
            NewN->next->prev = NewN;
        }
    }
    Length++;
}

template<class T>
void DLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }
    struct node<T> *Temp = Head;
    
    Head = Head->next;
    delete Temp;

    if(Head != NULL)
    {
        Head->prev = NULL;
    }

    Length--;
}

template<class T>
void DLL<T>::DeleteLast()
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

template <class T>
void DLL<T>::DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > Length || Head == NULL)
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

        if(Temp->next != NULL)
        {
            Temp->next->prev = Temp;
        }
    }
    Length--;
}

template<class T>
void DLL<T>::Display()
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
T DLL<T>::Search(int iPos)
{
    struct node<T> *Temp = Head;
    for(int iCnt = 1 ; iCnt < iPos -1 ; iCnt++)
    {
        Temp = Temp->next;
    }
    return Temp->data;
}

template<class T>
int DLL<T>::Count()
{
    return Length;
}

int main()
{
    int iChoice = 1;
    DLL <char>obj;
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
        cout<<"9 : Search the element"<<endl;
        cout<<"10 : Terminate the application"<<endl;
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
                cout<<"Enter the position : "<<endl;
                cin>>ipos;
                Value = obj.Search(ipos);
                cout<<"Value at position : "<<ipos<<" is "<<Value<<endl;
                break; 

            case 10:
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