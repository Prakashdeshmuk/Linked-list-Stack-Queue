#include<bits/stdc++.h>
using namespace std;

vector<int> help_classmate(vector<int> arr, int n) 
{ 
        stack<int> st;
        vector<int> ans(arr.size());
        st.push(-1);
        
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            int curr = arr[i];
            
            while(st.top()!=-1 && st.top()>=curr)
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(curr);
        }
        return ans;
} 

vector<int> help_classmateIndex(vector<int> arr, int n) 
{ 
        stack<int> st;
        vector<int> ans(arr.size());
        st.push(-1);
        
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            int curr = i;
            
            while(st.top()!=-1 && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(curr);
        }
        return ans;
} 

vector<int> leftSmaller(int n, int a[])
{
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        
        for(int i=0;i<n;i++)
        {
            int curr = a[i];
            
            while(st.top()!=-1 && st.top()>=curr)
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(curr);
        }
        return ans;
}


vector<int> leftSmallerIndex(int n, int a[])
{
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        
        for(int i=0;i<n;i++)
        {
            int curr = i;
            
            while(st.top()!=-1 && a[st.top()]>=a[i])
            {
                st.pop();
            }
            ans[i]=st.top();
            st.push(curr);
        }
        return ans;
}


int main()
{
    int vec[5]={3,8,5,2,25};
    vector<int> ans = leftSmallerIndex(5,vec);

    for(auto it:ans)
    {
        cout << it << " ";
    }
    return 0;
}