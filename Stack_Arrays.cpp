#include<iostream>
using namespace std;

#define MAX 15

class Stack
{
    int top;
    public:
        int arr[MAX];

        Stack() 
        { 
            top = -1; 
        
        }

        void push(int x)
        {
            top++;
            arr[top]=x;
            cout<<x<<" pushed into the stack\n";
            return;
        }

        int pop()
        {
            int x = arr[top];
            top--;
            return x;
        }

        int peek()
        {
            return arr[top];
        }

        bool isEmpty()
        {
            return (top<0);
        }

        bool isFull()
        {
            return (top>=MAX-1);
        }
};

int main()
{
    Stack s;
    char ch = 'y';
    while (ch=='y'||ch=='Y')
    {
        cout<<"Available operations on given stack(build with array)"<<endl;
        cout<<"1.\tPush an element into the stack"<<endl;
        cout<<"2.\tPop top from the stack"<<endl;
        cout<<"3.\tPrint top element of the stack"<<endl;
        cout<<"4.\tCheck if stack is empty or not"<<endl;
        int choice;
        cout<<"Enter your selection: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                if (s.isFull())
                {
                    cout<<"Stack Overflow"<<endl;
                }
                else
                {
                    int num;
                    cout<<endl;
                    cout<<"Enter value to push into the stack: ";
                    cin>>num;
                    s.push(num);
                }
                break;
            }
            case 2:
            {
                if (s.isEmpty())
                {
                    cout<<"Stack Underflow"<<endl;
                }
                else
                {
                    cout<<s.pop()<<" popped from the stack"<<endl;
                }
                break;
            }
            case 3:
            {
                if (s.isEmpty())
                {
                    cout<<"Stack is Empty"<<endl;
                }
                else
                {
                    cout<<s.peek()<<" is top element of the stack"<<endl;
                }
                break;
            }
            case 4:
            {
                if (s.isEmpty())
                {
                    cout<<"Stack is Empty"<<endl;
                }
                else
                {
                    cout<<"Stack is not empty"<<endl;
                }
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