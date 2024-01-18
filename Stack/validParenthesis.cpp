class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;

        for(int i=0;i<s.length();i++)
        {
            char ch= s[i];

            if(ch=='(' || ch=='{' || ch=='[')
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty())
                {
                    if(ch==')' && st.top()=='(')
                    {
                        st.pop();
                    }
                    else if(ch==']' && st.top()=='[')
                    {
                        st.pop();
                    }
                    else if(ch=='}' && st.top()=='{')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                
            }
        }

        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

int checkRedundancy(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch == '(' || ch=='+' || ch =='-' || ch=='*' || ch=='/' || ch =='%')
            {
                st.push(ch);
            }
            else if(ch==')')
            {
                int cnt = 0;
                while(!st.empty() && st.top()!='(')
                {
                    char temp = st.top();
                    if(temp == '(' || temp=='+' || temp =='-' || temp=='*' || temp=='/' || temp =='%')
                    {
                        cnt++;
                    }
                    st.pop();
                }
                st.pop();
                if(cnt==0)
                {
                    return true;
                }
               
            }
            
        }
        return false;
    }