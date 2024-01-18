 int celebrity(vector<vector<int> >& M, int n) 
    {
        // brute for
        // vector<int>in(M.size(),0);
        // vector<int>out(M.size(),0);
        // int ans = -1;
        
        // for(int i=0;i<M.size();i++)
        // {
        //     for(int j=0;j<M[i].size();j++)
        //     {
        //         if(M[i][j])
        //         {
        //             out[i]++;
        //             in[j]++;
        //         }
        //     }
        // }
        
        // for(int i=0;i<M.size();i++)
        // {
        //     if(in[i]==n-1 && out[i]==0)
        //     {
        //         ans = i;
        //     }
        // }
        // return ans;
        
        
        
        // push all member in the stack 
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        
        
        // we find which number uin the stack is might celebrity
        
        while(st.size()!=1)
        {
            int a=st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(M[a][b])
            {
                // it means is a is Not celebrity
                // b can be might celebrity
                
                st.push(b);
            }
            else
            {
                // b is not celebrity 
                st.push(a);
            }
        }
        
        int ans = st.top();
        
        for(int i=0;i<n;i++)
        {
            if(M[ans][i]==1)
            {
                return -1;
            }
        }
        
         for(int i=0;i<n;i++)
        {
            if(M[i][ans]!=1 && i!=ans)
            {
                return -1;
            }
        }
        
        return ans;
        
    }