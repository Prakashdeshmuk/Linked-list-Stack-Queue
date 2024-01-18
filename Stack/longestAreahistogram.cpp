class Solution {
public:
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

    vector<int> leftSmallerIndex(vector<int>a,int n)
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


    int largestRectangleArea(vector<int>& heights) {
        vector<int>next = help_classmateIndex(heights,heights.size());

        for(int i=0;i<heights.size();i++)
        {
            if(next[i]==-1)
            {
                next[i]=heights.size();
            }
        }
        vector<int>prev = leftSmallerIndex(heights,heights.size());

        vector<int> area;
        int maxi = INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int width = next[i]-prev[i]-1;
            int ans = heights[i]*width;
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};