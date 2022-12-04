
#include <iostream>
using namespace std;

class Cnode
{
    public:
        int data;
        Cnode* next;
};
Cnode* front = NULL;
Cnode* rear = NULL;

void enqueue_front(int val)
{
    Cnode* ob = new Cnode();
    if (!ob)
    {
        cout<<"Case of DEQUE OVERFLOW .";
    }

    ob->data=val;
    if (front==NULL)
    {
        front=rear=ob;
        ob->next=front;
    }
    else
    {
        ob->next=front;
        front=ob;
        rear->next=ob;
    }
}

void enqueue_back(int val)
{
     Cnode* ob = new Cnode();
    if (!ob)
    {
        cout<<"Case of DEQUE OVERFLOW .";
    }
    ob->data = val;
    if (front == NULL)
    {
        front=rear=ob;
        ob->next = front;;
    }
    else
    {
        rear->next=ob;
        rear=ob;
        rear->next=front;
    }
}


int dequeue_Front()
{
    int element = front->data;
    if (front==rear)
    {
        front=rear=NULL;
    }
    else if (front->next==rear)
    {
        front=rear;
        rear->next=front;
    }
    else
    {
        front=front->next;
        rear->next=front;
    }
    return element;
}


int dequeue_Back()
{
    int element = rear->data;
    if (front==rear)
    {
        front=rear=NULL;
    }
    else if (front->next==rear)
    {
        rear = front;
        front->next=front;
    }
    else
    {
        Cnode* temp = front;
        while (temp->next!=rear)
        {
            temp=temp->next;
        }
        temp->next=front;
        rear=temp;
    }
    return element;
}



void display()
{
    cout<<endl;
    if (front==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    Cnode* temp = front;
    cout<<temp->data<<" ";
    temp=temp->next;
    while(temp->data!=front->data)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

int main()
{
    char ch;
    do
    {
        cout<<"Available Operations on DEQUE->"<<endl;
        cout<<"1.\tInsertion in deque"<<endl;
        cout<<"2.\tDeletion in deque"<<endl;
        cout<<"3.\tDisplay deque"<<endl;
        cout<<"\nEnter your Selection: ";
        int s;
        cin>>s;
        switch(s)
        {
            case 1:
            {
                cout<<"\n1\tenqueue an element in front"<<endl;
                cout<<"2\tenqueue an element in End"<<endl;
                int s1;
                cout<<"\nEnter your Selection: ";
                cin>>s1;
                switch(s1)
                {
                    case 1:
                    {
                        cout<<"Enter number to add in queue = ";
                        int num;
                        cin>>num;
                        enqueue_front(num);
                        break;
                    }
                    case 2:
                    {
                        cout<<"Enter number to add in queue = ";
                        int num;
                        cin>>num;
                        enqueue_back(num);
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
                if (front==NULL)
                {
                    cout<<"\nCase of Underflow as no DEQUE is present to delete from."<<endl;
                    break;
                }
                cout<<"\n1\tDequeue from Front"<<endl;
                cout<<"2\tDequeue from End"<<endl;
                int s1;
                cout<<"\nEnter your Selection: ";
                cin>>s1;
                switch(s1)
                {
                    case 1:
                    {
                        if (front==NULL)
                        {
                            cout<<"\nNo QUEUE exist to delete from! CASE OF UNDERFLOW"<<endl;
                            break;
                        }
                        cout<<"Number dequeued is ="<<dequeue_Front();
                        break;
                    }
                    case 2:
                    {
                        if (rear==NULL)
                        {
                            cout<<"\nNo DEQUe exist to delete from! CASE OF UNDERFLOW"<<endl;
                            break;
                        }
                        cout<<"Number dequeued is ="<<dequeue_Back();
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
                if (front==NULL)
                {
                    cout<<"\nNo DEQUE exist to display ."<<endl;
                    break;
                }
                display();
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
