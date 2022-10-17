#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};
Node* head = NULL;
int size = 1;

void insertion_Front(int val)
{
    Node* ob = new Node();
    ob->data = val;
    ob->next = head;
    head = ob;
    size++;
}

void insertion_Back(int val)
{
    Node* ob = new Node();
    ob->data = val;
    if (head == NULL)
    {
        head = ob;
        ob->next = NULL;
    }
    else
    {
        Node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = ob;
        ob->next = NULL;
    }
    size++;
}

void insertion_Index(int index)
{
    if (index<1)
    {
        cout<<"\nInvalid Input"<<endl;
        return;
    }
    else if(index>size)
    {
        cout<<"\nOverflow"<<endl;
        return;
    }
    cout<<"Enter element: ";
    int num;
    cin>>num;
    if (index==1)
    {
        insertion_Front(num);
        return;
    }
    int i=1;
    Node* temp = head;
    while (temp!=NULL)
    {
        if (i==index-1)
        {
            break;
        }
        i++;
        temp = temp->next;
    }
    Node* ob = new Node();
    ob->data = num;
    ob->next=temp->next;
    temp->next=ob;
    size++;
}

void deletion_Front()
{
    head=head->next;
    size--;
}

void deletion_Back()
{
    Node* temp = head;
    if (head->next==NULL)
    {
        head=NULL;
    }
    else
    {
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NULL;
    }
    size--;
}

void deletion_Index(int index)
{
    if (index<1)
    {
        cout<<"\nUnderflow"<<endl;
        return;
    }
    else if(index>=size)
    {
        cout<<"\nInvalid Input"<<endl;
        return;
    }
    if (index==1)
    {
        deletion_Front();
        return;
    }
    int i=1;
    Node* temp = head;
    while (temp!=NULL)
    {
        if (i==index-1)
        {
            break;
        }
        i++;
        temp = temp->next;
    }
    temp->next=temp->next->next;
    size--;
}

int searchLL(int x)
{
    Node* temp = head;
    int i=0;
    while (temp!=NULL)
    {
        if (temp->data==x)
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
    Node* head1 = NULL;
    Node* head2 = NULL;
    cout<<"Enter number of elements for 1st LL: ";
    int n1;
    cin>>n1;
    for (int i=0;i<n1;i++)
    {
        cout<<"Enter "<<i+1<<" value: ";
        int num;
        cin>>num;
        Node* ob = new Node();
        ob->data = num;
        ob->next = head1;
        head1 = ob;
    }
    cout<<"Enter number of elements for 2nd LL: ";
    int n2;
    cin>>n2;
    for (int i=0;i<n2;i++)
    {
        cout<<"Enter "<<i+1<<" value: ";
        int num;
        cin>>num;
        Node* ob = new Node();
        ob->data = num;
        ob->next = head2;
        head2 = ob;
    }
    Node* temp = head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    temp=head1;
    head=head1;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    size = n1+n2;
}

void display()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main()
{
    char ch;
    do
    {
        cout<<"Available Operations on Linked List->"<<endl;
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
                        cout<<"\nEnter Index position: ";
                        int index;
                        cin>>index;
                        insertion_Index(index);
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
                        cout<<"\nEnter Index position: ";
                        int index;
                        cin>>index;
                        deletion_Index(index);
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
                    cout<<"\nElement found in the Linked List at "<<index+1<<" position"<<endl;
                }
                break;
            }
            case 4:
            {
                concat();
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