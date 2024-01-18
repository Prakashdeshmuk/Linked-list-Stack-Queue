class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> st;
        st.push(0);

        for(int i=temperatures.size()-1;i>=0;i--)
        {
            while(st.top()!=0 && temperatures[st.top()]<=temperatures[i])
            {
                st.pop();
            }

            if(st.top()==0)
            {
                ans[i]=0;
            }
            else
            {
                ans[i]=st.top()-i;
            }

            st.push(i);
        }
        return ans;
    }
};