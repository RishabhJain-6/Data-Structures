#include<iostream>
using namespace std;

class Queue
{
    public:
        int front;
        int rear;
        int size;
        int *arr;

        Queue(int s)
        {
            front = rear = -1;
            size = s;
            arr = new int[s];
        }

        void enQueue(int val)
        {
            if ((front==0 && rear==size-1) || (rear==(front-1)%(size-1)))
            {
                cout<<"Queue is full"<<endl;
                return;
            }
            else if(front==-1)
            {
                front = rear = 0;
                arr[rear] = val;
            }
            else if (rear==size-1 && front!=0)
            {
                rear = 0;
                arr[rear]=val;
            }
            else
            {
                rear++;
                arr[rear]=val;
            }
        }

        int deQueue()
        {
            if (front==-1)
            {
                cout<<"Queue is empty"<<endl;
                return 0;
            }
            int data = arr[front];
            arr[front]=-1;
            if (front==rear)
            {
                front = rear = -1;
            }
            else if (front==size-1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
            return data;
        }

        int front_queue()
        {
            if (front==-1)
            {
                return 0;
            }
            return arr[front];
        }

        void display()
        {
            if (front==-1)
            {
                cout<<"Queue is Empty"<<endl;
                return;
            }
            cout<<"Elements in the queue are-> \t";
            if(rear>=front)
            {
                for (int i=front;i<=rear;i++)
                {
                    cout<<arr[i]<<"  ";
                }
                cout<<endl;
            }
            else
            {
                for (int i=front;i<size;i++)
                {
                    cout<<arr[i]<<"  ";
                }
                for (int i=0;i<=rear;i++)
                {
                    cout<<arr[i]<<"  ";
                }
            }
        }
};

int main()
{
    Queue q(5);
    char ch = 'y';
    while (ch=='y'||ch=='Y')
    {
        cout<<"Available operations on given stack(build with array)"<<endl;
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
                cout<<"Enter value to push into the stack: ";
                cin>>num;
                q.enQueue(num);
                break;
            }
            case 2:
            {
                int a = q.deQueue();
                if (a!=0)
                {
                    cout<<a<<" removed from queue"<<endl;
                }
                break;
            }
            case 3:
            {
                int a = q.front_queue();
                if (a!=0)
                {
                    cout<<"Front: "<<a<<endl;
                }
                break;
            }
            case 4:
            {
                q.display();
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