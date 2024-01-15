#include <bits/stdc++.h>
using namespace std;

class Stack
{
    public:
    int size;
    int top ;
    int *arr;

    Stack()
    {
        size = 1000;
        top = -1;
        arr = new int[size];
    }

    void push(int x)
    {
        if(top==size-1)
        {
            cout << "Overflow" << endl;
            return;
        }
        top++;
        arr[top]=x;
    }

    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if(top==size-1)
        {
            return true;
        }
        return false;
    }

    void pop()
    {
        if(top==-1)
        {
            cout << "Underflow" << endl;
            return;
        }
        top--;
    }

    int getTop()
    {
        if(top==-1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }

};

int main()
{
    Stack obj;
    obj.push(20);
    obj.pop();

    int top = obj.getTop();
    cout << top << endl;
}