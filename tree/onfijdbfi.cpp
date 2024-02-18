#include<bits/stdc++.h>
using namespace std;


int main()
{
    set<int> st;
    st.insert(5);
    st.insert(4);
    st.insert(3);
    st.insert(6);

    set<int>::iterator it;

    it = st.find(5);

    st.erase(it);

    for(auto it:st)
    {
        cout << it << " ";
    }
}