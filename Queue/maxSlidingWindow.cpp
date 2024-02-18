#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        //brute force approach
        // vector<int> ans;

        // for(int i=0;i<=n-k;i++ )
        // {
        //     int maxi = arr[i];

        //     for(int j=i;j<k+i;j++)
        //     {
        //         maxi = max(maxi,arr[j]);
        //     }
        //     ans.push_back(maxi);
        // }
        // return ans;

        // tc->O(n*k)
        
        
        // optimal approach
        
        // ek window process karlo
        //remaing window process
        //1->remove those element which are out of range 
        //2->remove those element which are lessar than curr element
        //3->add element in window 
        //4->last window ka ans last me milega 
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0;i<k;i++)
        {
            int element = arr[i];
            
            while(!dq.empty() && element>arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        for(int i=k;i<n;i++)
        {
            ans.push_back(arr[dq.front()]);
            
            // remove those element which are out of range 
            
            if(!dq.empty() && i-dq.front()>=k)
            {
                dq.pop_front();
            }
            
            int element = arr[i];
            
            while(!dq.empty() && element>arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
        }
        ans.push_back(arr[dq.front()]);
        
        return ans;

        // tc->O(n)
    }


    vector <int> min_of_subarrays(int *arr, int n, int k)
    {
        // max window of size of k 

        //1->one window process karo
        //2->ans niklo 
        //3->remove those element whose out of window 
        //4->remove those which are smaller than current element 


        deque<int> dq;// it store index of Number 
        vector<int> ans;

        // ek window process karo 

        for(int i=0;i<k;i++)
        {
            int element = arr[i];

            while(!dq.empty() && element<arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // remaining window process karo 
        // remove those element which are out of window ->i-dq.front()>=k
        for(int i=k;i<n;i++)
        {
            ans.push_back(arr[dq.front()]);

            if(!dq.empty() && i-dq.front()>=k)
            {
                dq.pop_front();
            }

            int element = arr[i];

            while(!dq.empty() && element<arr[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);


        }


        // last window ka ans 

        ans.push_back(arr[dq.front()]);

        return ans;

    }
};


int main()
{
    Solution obj;
    int size = 7;
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    vector<int> mini = obj.max_of_subarrays(arr,size,k);

    vector<int> maxi = obj.min_of_subarrays(arr,size,k);
    int ans = 0;

    for(int i=0;i<k;i++)
    {
        ans+=mini[i]+maxi[i];
    }

    cout << "Ans:" << ans << endl;


}