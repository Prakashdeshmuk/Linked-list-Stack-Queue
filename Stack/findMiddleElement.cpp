#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> & st,int pos,int &ans)
{
    if(pos==1)
    {
        ans = st.top();
        return;
    }

    int temp = st.top();
    st.pop();
    pos--;

    solve(st,pos,ans);

    st.push(temp);
}

int getMiddleElement(stack<int> &st)
{
    if(st.empty())
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else
    {
        int size = st.size();
        int pos = 0;
        int ans = -1;
        if(size&1)
        {
            pos = size/2+1;
        }
        else
        {
            pos = size/2;
        }
        solve(st,pos,ans);
        return ans;

    }
}


void insertAtbottom(stack<int> &st,int element)
{
    if(st.empty())
    {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtbottom(st,element);
    st.push(temp);
}

void reversestack(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();
    reversestack(st);
    insertAtbottom(st,temp);
}


void insertElementSortedStack(stack<int>&st,int element)
{
    if(st.empty() || element>=st.top())
    {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();
    insertElementSortedStack(st,element);
    st.push(temp);
}

void sortedstack(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();

    sortedstack(st);

    insertElementSortedStack(st,temp);
}

int main()
{
    stack<int> st;
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(10);
    st.push(20);
    st.push(30);
    

    // int middle = getMiddleElement(st);
    // cout << "Middle Element:" << middle << endl;

    // cout << st.top() << endl;

    // insertAtbottom(st,456);
    // reversestack(st);

    // insertElementSortedStack(st,500);
    sortedstack(st);

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }



    
    return 0;
}