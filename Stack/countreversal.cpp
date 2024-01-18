int countRev (string s)
{
    if(s.length()&1) return -1;
    int ans = 0;
    stack<char>st;
    
    for(auto ch:s)
    {
        if(ch=='{')
        {
            st.push(ch);
        }
        else
        {
            if(st.empty()==false && st.top()=='{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    while(st.empty()==false)
    {
        char ch1 = st.top();
        st.pop();
        char ch2 = st.top();
        st.pop();
        if(ch1==ch2)
        {
            ans+=1;
        }
        else
        {
            ans+=2;
        }
    }
    return ans;
}