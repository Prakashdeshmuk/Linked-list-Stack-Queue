class Solution
{
    public:
    
   
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> st;
        int cnt = q.size()-k;
        while(k)
        {
            st.push(q.front());
            q.pop();
            k--;
        }
        
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        
        
        while(cnt)
        {
          int temp = q.front();
          q.pop();
          q.push(temp);
          cnt--;
        }
        return q;
    }
};