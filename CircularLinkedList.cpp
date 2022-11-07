#include <iostream>
using namespace std;

class Cnode
{
    public:
        int data;
        Cnode* next;
};
Cnode* head = NULL;
Cnode* tail = NULL;
int size = 1;

void insertion_Front(int val)
{
    Cnode* ob = new Cnode();
    ob->data=val;
    if (head==NULL)
    {
        head=tail=ob;
        ob->next=head;
    }
    else
    {
        ob->next=head;
        head=ob;
        tail->next=ob;
    }
    size++;
}

void insertion_Back(int val)
{
    Cnode* ob = new Cnode();
    ob->data = val;
    if (head == NULL)
    {
        head=tail=ob;
        ob->next = head;
    }
    else
    {
        tail->next=ob;
        tail=ob;
        tail->next=head;
    }
    size++;
}

void insertion_Index(int value)
{
    cout<<"Enter data: ";
    int num;
    cin>>num;
    Cnode* temp = head;
    while (temp->data!=value)
    {
        temp=temp->next;
    }
    if (temp==tail)
    {
        insertion_Back(num);
        return;
    }
    else
    {
        Cnode* ob = new Cnode();
        ob->data = num;
        ob->next = temp->next;
        temp->next = ob;
    }
    size++;
}

void deletion_Front()
{
    if (head==tail)
    {
        head=tail=NULL;
    }
    else if (head->next==tail)
    {
        head=tail;
        tail->next=head;
    }
    else
    {
        head=head->next;
        tail->next=head;
    }
    size--;
}

void deletion_Back()
{
    if (head==tail)
    {
        head=tail=NULL;
    }
    else if (head->next==tail)
    {
        tail = head;
        head->next=head;
    }
    else
    {
        Cnode* temp = head;
        while (temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=head;
        tail=temp;
    }
    size--;
}

void deletion_Index(int value)
{
    if (head->data==value)
    {
        deletion_Front();
        return;
    }
    else if (tail->data==value)
    {
        deletion_Back();
        return;
    }
    else
    {
        Cnode* temp = head;
        while (temp->next->data!=value)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
    size--;
}

int searchLL(int x)
{
    Cnode* temp = head;
    int i=0;
    while (temp!=tail)
    {
        if (temp->data==x)
        {
            return i;
        }
        i++;
        temp=temp->next;
    }
    if (tail->data==x)
    {
        i++;
        return i;
    }
    return -1;
}

void concat()
{
    Cnode* head1 = NULL;
    Cnode* head2 = NULL;
    Cnode* tail1 = NULL;
    Cnode* tail2 = NULL;
    cout<<"Enter number of elements for 1st LL: ";
    int n1;
    cin>>n1;
    for (int i=0;i<n1;i++)
    {
        cout<<"Enter "<<i+1<<" value: ";
        int num;
        cin>>num;
        insertion_Back(num);
    }
    head1 = head;
    tail1 = tail;
    head = tail = NULL;
    cout<<"Enter number of elements for 2nd LL: ";
    int n2;
    cin>>n2;
    for (int i=0;i<n2;i++)
    {
        cout<<"Enter "<<i+1<<" value: ";
        int num;
        cin>>num;
        insertion_Back(num);
    }
    head2 = head;
    tail2 = tail;
    head = head1;
    tail1->next = head2;
    tail2->next=head1;
    tail = tail2;
    size = n1+n2+1;
}

void display()
{
    cout<<endl;
    if (head==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    Cnode* temp = head;
    cout<<temp->data<<"->";
    temp=temp->next;
    while(temp!=head)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<head->data<<endl;
}

int main()
{
    char ch;
    do
    {
        cout<<"Available Operations on Circular Linked List->"<<endl;
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
                cout<<"3\tInsertion after some Node"<<endl;
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
                            cout<<"Enter "<<i+1<<" element: ";
                            int num;
                            cin>>num;
                            insertion_Front(num);
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
                            cout<<"Enter "<<i+1<<" element: ";
                            int num;
                            cin>>num;
                            insertion_Back(num);
                        }
                        cout<<endl;
                        display();
                        break;
                    }
                    case 3:
                    {
                        if (head==NULL)
                        {
                            cout<<"Invalid Input!!"<<endl;
                            break;
                        }
                        cout<<"\nEnter value after which u want to enter new node: ";
                        int value;
                        cin>>value;
                        int ext = searchLL(value);
                        if (ext!=-1)
                        {
                            insertion_Index(value);
                            display();
                        }
                        else
                        {
                            cout<<"Invalid Input!!"<<endl;
                        }
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
                cout<<"3\tDeletion of given value"<<endl;
                int s1;
                cout<<"\nEnter your Selection: ";
                cin>>s1;
                switch(s1)
                {
                    case 1:
                    {
                        deletion_Front();
                        display();
                        break;
                    }
                    case 2:
                    {
                        deletion_Back();
                        display();
                        break;
                    }
                    case 3:
                    {
                        cout<<"\nEnter value to be deleted: ";
                        int value;
                        cin>>value;
                        int check = searchLL(value);
                        if (check!=-1)
                        {
                            deletion_Index(value);
                            display();
                        }
                        else
                        {
                            cout<<"Invalid Input!!"<<endl;
                        }
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
                    cout<<"\nElement found in the Linked List at "<<index+1<<" position"<<endl;
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
