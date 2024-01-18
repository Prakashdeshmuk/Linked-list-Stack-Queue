vector <int> calculateSpan(int price[], int n)
    {
    //   vector<int> ans(n,1);
    //   ans[0]=1;
       
    //   for(int i=1;i<n;i++)
    //   {
    //       int j = i-1;
    //       while(j>=0 && price[i]>=price[j])
    //       {
    //           ans[i]++;
    //           j--;
    //       }
    //   }
    //   return ans;
    
    
    // optimal approach
    // stack<pair<int,int>>st;
    // st.push({-1,1});
    // vector<int> ans(n);
    // ans[0]=1;
    // for(int i=1;i<n;i++)
    // {
    //     int span = 1;
    //     while(st.top().first!=-1 && st.top().first<=price[i])
    //     {
    //         span+=st.top().second;
    //         st.pop();
    //     }
    //     st.push({price[i],span});
    //     ans[i]=span;
        
    // }
    // return ans;
        
    // }
    
    
    
    // approach 3
    
    stack<int> st;
    vector<int> ans;
    
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && price[i]>=price[st.top()])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans.push_back(i+1);
        }
        else
        {
            ans.push_back(i-st.top());
        }
        st.push(i);
    }
    return ans;
 }