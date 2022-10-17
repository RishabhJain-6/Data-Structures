#include <iostream>
using namespace std;

class Dnode
{
    public:
        int data;
        Dnode* next;
        Dnode* prev;
};

Dnode* head = NULL;
Dnode* tail = NULL;
int size = 1;

void insertion_Front()
{
    cout<<"Enter data: ";
    int num;
    cin>>num;
    Dnode* ob = new Dnode();
    ob->data=num;
    if(head==NULL)
    {
        head=ob;
        ob->prev=NULL;
        ob->next=NULL;
        tail=ob;
    }
    else
    {
        head->prev=ob;
        ob->next=head;
        head=ob;
        head->prev=NULL;
    }
    size++;
}

void insertion_Back()
{
    cout<<"Enter data: ";
    int num;
    cin>>num;
    Dnode* ob = new Dnode();
    ob->data=num;
    if(tail==NULL)
    {
        tail=ob;
        ob->prev=NULL;
        ob->next=NULL;
        head=ob;
    }
    else
    {
        tail->next=ob;
        ob->prev=tail;
        tail=ob;
        tail->next=NULL;
    }
    size++;
}

void insertion_Index()
{
    cout<<"Enter Position: ";
    int pos;
    cin>>pos;
    if (pos<=0)
    {
        cout<<"\nInvalid Input!";
        return;
    }
    else if (pos>size)
    {
        cout<<"List Overflow!!"<<endl;
        return;
    }
    else if (pos==1)
    {
        insertion_Front();
        return;
    }
    else if (pos==size)
    {
        insertion_Back();
        return;

    }
    else
    {
        Dnode* temp = head;
        for (int i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        cout<<"Enter data: ";
        int num;
        cin>>num;
        Dnode* ob = new Dnode();
        ob->data=num;
        ob->next = temp->next;
        temp->next=ob;
        ob->prev = temp;
        ob->next->prev = ob;
    }
    size++;
}

void delete_Front()
{
    Dnode* temp = head;
    if (head==tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
    size--;
}

void delete_Back()
{
    Dnode* temp = tail;
    if (head==tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
    size--;
}

void delete_Index()
{
    cout<<"Enter Position: ";
    int pos;
    cin>>pos;
    if (pos<=0 || pos>=size)
    {
        cout<<"\nInvalid Input!"<<endl;
        return;
    }
    else if (pos==1)
    {
        delete_Front();
        return;
    }
    else if (pos==size-1)
    {
        delete_Back();
        return;

    }
    else
    {
        Dnode* temp = head;
        for (int i=1;i<=pos-1;i++)
        {
            temp=temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    size--;
}

int searchLL(int target)
{
    Dnode* temp = head;
    int i = 1;
    while (temp!=NULL)
    {
        if (temp->data==target)
        {
            return i;
        }
        i++;
        temp=temp->next;
    }
    return -1;
}

void concat()
{
    Dnode* head1 = NULL;
    Dnode* head2 = NULL;
    Dnode* tail1 = NULL;
    Dnode* tail2 = NULL;
    cout<<"Enter number of elements for 1st LL: ";
    int n1;
    cin>>n1;
    for (int i=0;i<n1;i++)
    {
        cout<<"Enter "<<i+1<<" value: ";
        int num;
        cin>>num;
        Dnode* ob = new Dnode();
        ob->data=num;
        if(tail1==NULL)
        {
            tail1=ob;
            ob->prev=NULL;
            ob->next=NULL;
            head1=ob;
        }
        else
        {
            tail1->next=ob;
            ob->prev=tail1;
            tail1=ob;
            tail1->next=NULL;
        }
    }
    cout<<"Enter number of elements for 2nd LL: ";
    int n2;
    cin>>n2;
    for (int i=0;i<n2;i++)
    {
        cout<<"Enter "<<i+1<<" value: ";
        int num;
        cin>>num;
        Dnode* ob = new Dnode();
        ob->data=num;
        if(tail2==NULL)
        {
            tail2=ob;
            ob->prev=NULL;
            ob->next=NULL;
            head2=ob;
        }
        else
        {
            tail2->next=ob;
            ob->prev=tail2;
            tail2=ob;
            tail2->next=NULL;
        }
    }
    tail1->next=head2;
    head=head1;
    tail=tail2;
    size = n1+n2;
}

void display()
{
    Dnode* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    char ch;
    do
    {
        cout<<"Available Operations on Doubly Linked List->"<<endl;
        cout<<"1.\tInsertion"<<endl;
        cout<<"2.\tDeletion"<<endl;
        cout<<"3.\tSearching"<<endl;
        cout<<"4.\tConcatenate two lists"<<endl;
        cout<<"5.\tSize of Linked List"<<endl;
        cout<<"\nEnter your Selection: ";
        int s;
        cin>>s;
        switch(s)
        {
            case 1:
            {
                cout<<"\n1\tInsertion at Front"<<endl;
                cout<<"2\tInsertion at End"<<endl;
                cout<<"3\tInsertion at some index"<<endl;
                int s1;
                cout<<"\nEnter your Selection: ";
                cin>>s1;
                switch(s1)
                {
                    case 1:
                    {
                        cout<<"\nEnter number of elements: ";
                        int n;
                        cin>>n;
                        cout<<endl;
                        for (int i=0;i<n;i++)
                        {
                            insertion_Front();
                        }
                        cout<<endl;
                        display();
                        break;
                    }
                    case 2:
                    {
                        cout<<"\nEnter number of elements: ";
                        int n;
                        cin>>n;
                        cout<<endl;
                        for (int i=0;i<n;i++)
                        {
                            insertion_Back();
                        }
                        cout<<endl;
                        display();
                        break;
                    }
                    case 3:
                    {
                        insertion_Index();
                        display();
                        break;
                    }
                    default:
                    {
                        cout<<"\nInvalid Input";
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                if (head==NULL)
                {
                    cout<<"\nCase of Underflow as no  Linked List exists"<<endl;
                    break;
                }
                cout<<"\n1\tDeletion at Front"<<endl;
                cout<<"2\tDeletion at End"<<endl;
                cout<<"3\tDeletion at some index"<<endl;
                int s1;
                cout<<"\nEnter your Selection: ";
                cin>>s1;
                switch(s1)
                {
                    case 1:
                    {
                        delete_Front();
                        display();
                        break;
                    }
                    case 2:
                    {
                        delete_Back();
                        display();
                        break;
                    }
                    case 3:
                    {
                        delete_Index();
                        display();
                        break;
                    }
                    default:
                    {
                        cout<<"\nInvalid Input";
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                if (head==NULL)
                {
                    cout<<"\nNo Linked List exist to search from!"<<endl;
                    break;
                }
                cout<<"\nEnter the element u want to search: ";
                int num;
                cin>>num;
                int index = searchLL(num);
                if (index==-1)
                {
                    cout<<"\nGiven element not present in the Linked List";
                }
                else
                {
                    cout<<"\nElement found in the Linked List at "<<index<<" position"<<endl;
                }
                break;
            }
            case 4:
            {
                concat();
                display();
                break;
            }
            case 5:
            {
                cout<<"\nCurrent size of Linked List: "<<size<<endl;
                break;
            }
            default:
            {
                cout<<"\nInvalid Input";
                break;
            }
        }
        cout<<"\nEnter y to continue or press any key to exit: ";
        cin>>ch;
    }
    while(ch=='y');
}