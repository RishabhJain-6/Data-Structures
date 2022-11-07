#include <iostream>
using namespace std;

#define MAX 6

class Queue
{
    public:
        int data;
        Queue* next;
};
Queue* front = NULL;
Queue* rear = NULL;
int size = 0;

void enQueue(int val)
{
    Queue* ob = new Queue();
    ob->data = val;
    if (front == NULL)
    {
        front=rear=ob;
        ob->next = front;
    }
    else
    {
        rear->next=ob;
        rear=ob;
        rear->next=front;
    }
    size++;
}

void deQueue()
{
    int a = front->data;
    if (front==rear)
    {
        front=rear=NULL;
    }
    else if (front->next==rear)
    {
        front=rear;
        rear->next=rear;
    }
    else
    {
        front=front->next;
        rear->next=front;
    }
    cout<<a<<" removed from the queue"<<endl;
    size--;
}

void front_queue()
{
    if (front==NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Front: "<<front->data<<endl;
}

void display()
{
    cout<<"Elements in the Queue are: \t";
    if (front==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    Queue* temp = front;
    cout<<temp->data;
    temp=temp->next;
    while(temp->data!=front->data)
    {
        cout<<"->"<<temp->data;
        temp = temp->next;
    }
}

int main()
{
    char ch = 'y';
    while (ch=='y'||ch=='Y')
    {
        cout<<"Available operations on given queue(build with circular linked list)"<<endl;
        cout<<"1.\tEnqueue"<<endl;
        cout<<"2.\tDequeue"<<endl;
        cout<<"3.\tFront of Queue"<<endl;
        cout<<"4.\tDisplay Queue"<<endl;
        int choice;
        cout<<"Enter your selection: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int num;
                cout<<endl;
                cout<<"Enter value : ";
                cin>>num;
                if (size==MAX)
                {
                    cout<<"Queue is full"<<endl;
                    break;
                }
                enQueue(num);
                break;
            }
            case 2:
            {
                if (front==NULL)
                {
                    cout<<"Queue is empty"<<endl;
                    break;
                }
                deQueue();
                break;
            }
            case 3:
            {
                front_queue();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            default:
            {
                cout<<"Invalid selection"<<endl;
                break;
            }
        }
        cout<<endl;
        cout<<"Enter y to continue or press any key to exit-> ";
        cin>>ch;
    }
}