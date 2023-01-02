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
class DCL
{
    private:
        struct node<T>* Head;
        struct node<T>* Tail;
        int Length;

    public:
        DCL();
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
DCL<T>::DCL()
{
    Head = NULL;
    Tail = NULL;
    Length = 0;
}

template <class T>
void DCL<T>::InsertFirst(T No)
{
    struct node<T>* NewN = NULL;

    NewN = new node<T>;

    NewN->data = No;
    NewN->next = NULL;
    NewN->prev = NULL;

    if(Length == 0)
    {   
        Head = NewN;
        Tail = NewN;
        NewN->next = NewN;
        NewN->prev = NewN;
    }
    else
    {
        NewN->next = Head;
		Head->prev = NewN;
        Tail->next = NewN;
        NewN->prev = Tail;
    }

    Head = NewN;

    Length++;
}

template <class T>
void DCL<T>::InsertLast(T No)
{
    struct node<T>* NewN = NULL;

    NewN = new node<T>;

    NewN->data = No;
    NewN->next = NULL;
    NewN->prev = Tail;
    
    if(Length == 0)
    {   
        Head = NewN;
        Tail = NewN;
        NewN->next = NewN;
        NewN->prev = NewN;
    }
    else
    {
        Tail->next = NewN;
        NewN->prev = Tail;
        NewN->next = Head;
        Head->prev = NewN;
    }
    Tail = NewN;
    Length++;
}

template <class T>
void DCL<T>::InsertAtPos(int iPos, T No)
{
    if((iPos < 1) || (iPos > Length+1 ))
    {
        cout<<"Invalid Index"<<endl;
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == Length+1)
    {
        InsertLast(No);
    }
    else
    {
        struct node<T>* NewN = NULL;
        struct node<T>* Temp = Head;

        NewN = new node<T>;
        NewN->data = No;
        NewN->next = NULL;
        NewN->prev = NULL;

        for(int iCnt = 1 ; iCnt < iPos-1 ; iCnt++)
        {
            Temp = Temp->next;
        }

        NewN->next = Temp->next;
        Temp->next = NewN;
        NewN->prev = Temp;
        NewN->next->prev = NewN;
        Length++;
    }
}

template <class T>
void DCL<T>::DeleteFirst()
{
    if(Length == 0)
    {
        return;
    }

    if(Head == Tail)
    {
        delete Head;
        Head =NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
        Tail->next = Head;
        Head->prev = Tail;
    }
    Length--;
}

template <class T>
void DCL<T>::DeleteLast()
{
    if(Length == 0)
    {
        return;
    }

    if(Head == Tail)
    {
        delete Head;
        Head =NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Tail->next;
        Tail->next = Head;
        Head->prev = Tail;
    }
    Length--;
}

template <class T>
void DCL<T>::DeleteAtPos(int iPos)
{
    if(Length == 0)
    {
        return;
    }

    if((iPos < 1) || (iPos > Length))
    {
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == Length)
    {
        DeleteLast();
    }
    else
    {
        struct node<T>* Temp = Head;

        for(int iCnt = 1 ; iCnt < iPos - 1 ;iCnt++)
        {
            Temp = Temp->next;
        }

        Temp->next = Temp->next->next;
        delete Temp->next->prev;
        Temp->next->prev = Temp;
        Length--;
    }
}

template<class T>
void DCL<T>::Display()
{
    struct node<T> *Temp = Head;
	
	if((Head == NULL) && (Tail == NULL))
	{
		return ;
	}
	
	do
	{
		cout<<"|"<<Temp->data<<"|->";
		Temp = Temp -> next;
	}while(Temp != Head);

    cout<<endl;
}

template<class T>
T DCL<T>::Search(int iPos)
{
    struct node<T> *Temp = Head;
    if(iPos < 1 || iPos > Length)
    {
        cout<<"Exception : Index out of Bound"<<endl;
        throw "Index out of Bound";
    }
    for(int iCnt = 1 ; iCnt < iPos ; iCnt++)
    {
        Temp = Temp->next;
    }
    return Temp->data;
}

template<class T>
int DCL<T>::Count()
{
    return Length;
}

int main()
{
    int iChoice = 1;
    DCL <char>obj;
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
                try{
                    Value = obj.Search(ipos);
                }
                catch(...)
                {
                    break;
                }
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