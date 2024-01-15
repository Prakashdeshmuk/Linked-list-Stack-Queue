#include <bits/stdc++.h>
using namespace std;

class Stack{

    public:
    int size;
    int top1,top2;
    int *arr;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int x)
    {
        if(top2-top1==1)
        {
            cout << "Overflow" << endl;
            return;
        }
        else
        {
            top1++;
            arr[top1]=x;
        }
        
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       if(top2-top1==1)
        {
            cout << "Overflow" << endl;
            return;
        }
        else
        {
            top2--;
            arr[top2]=x;
            
        }
        
    }
    
    //Function to remove an element from top of the stack1.
    void pop1()
    {
        if(top1==-1)
        {
            cout << "Underflow" << endl;
            return ;
        }
        arr[top1]=0;
        top1--;
        
    }
    
    //Function to remove an element from top of the stack2.
    void pop2()
    {
       if(top2==size)
        {
            cout << "Underflow" << endl;
            return ;
        }
        arr[top2]=0;
        top2++;
    }

    void print()
    {
        for(int i=0;i<size;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(10);
    st.push1(10);
    st.push2(20);
    st.push2(20);
    st.push2(20);
    st.push2(20);
    st.push2(20);
    st.push2(20);
    st.push2(20);
    st.push2(20);
    st.push2(20);
    st.pop2();
    st.push2(10);
    st.print();
    return 0;
}