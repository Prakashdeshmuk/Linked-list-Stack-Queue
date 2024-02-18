vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> ans;
    deque<long long int> dq;
    
    long long int i;
    
    for(i=0;i<K;i++)
    {
        if(A[i]<0)
        {
            dq.push_back(i);
        }
    }
    
    
    for(i=K;i<N;i++)
    {
        if(!dq.empty())
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
        
        
        if(!dq.empty())
        {
            if(i-dq.front()>=K)
            {
                dq.pop_front();
            }
        }
        
        if(A[i]<0)
        {
            dq.push_back(i);
        }
    }
    
    if(!dq.empty())
    {
            ans.push_back(A[dq.front()]);
    }
    else
    {
            ans.push_back(0);
    }
    
    return ans;
    
                                                 
 }