class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int>q1,q2;
        int n = q.size();
        
        for(int i=0;i<n/2;i++)
        {
            q1.push(q.front());
            q.pop();
        }
        
        
        for(int i=0;i<n/2;i++)
        {
            q2.push(q.front());
            q.pop();
        }
        
        
        for(int i=0;i<n/2;i++)
        {
            q.push(q1.front());
            q1.pop();
            q.push(q2.front());
            q2.pop();
        }
    
        vector<int> ans;
        
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
        
    }
};