#include<iostream>
using namespace std;

#define MAX 15

class Stack
{
    public:
        int data;
        Stack* next;

        Stack(int a)
        {
            data = a;
            next=NULL;
        }
};

Stack* top = NULL;
int size = 0;

void push(int num)
{
    if (size==MAX)
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    Stack* ob = new Stack(num);
    ob->next = top;
    top = ob;
    size++;
    cout<<num<<" pushed into the stack"<<endl;
}

void pop()
{
    if (size==0)
    {
        cout<<"Stack Underflow"<<endl;
        return;
    }
    int a = top->data;
    top = top->next;
    size--;
    cout<<a<<" popped from the stack"<<endl;
}

void peek()
{
    if (top==NULL)
    {
        cout<<"Empty Stack"<<endl;
        return;
    }
    cout<<"Top element of stack: "<<top->data<<endl;
}

void isEmpty()
{
    if (top==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        cout<<"Stack is not empty"<<endl;
    }
}

void clear()
{
    while (top!=NULL)
    {
        int a = top->data;
        top = top->next;
        cout<<a<<" popped from the stack"<<endl;
    }
    cout<<"Stack cleared"<<endl;
}

void size_stack()
{
    cout<<"Current size of the stack: "<<size<<endl;
}

int main()
{
    char ch = 'y';
    while (ch=='y'||ch=='Y')
    {
        cout<<"Available operations on given stack(build with linked list)"<<endl;
        cout<<"1.\tPush an element into the stack"<<endl;
        cout<<"2.\tPop top from the stack"<<endl;
        cout<<"3.\tPrint top element of the stack"<<endl;
        cout<<"4.\tCheck if stack is empty or not"<<endl;
        cout<<"5\tClear the stack"<<endl;
        cout<<"6\tPrint current number of elements in the stack"<<endl;
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
                push(num);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                isEmpty();
                break;
            }
            case 5:
            {
                clear();
                break;
            }
            case 6:
            {
                size_stack();
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
