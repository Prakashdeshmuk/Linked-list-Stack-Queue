#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n,x,y;
        cin >> n >> x >> y;
        vector<long long int> vec;
        for(int i=0;i<n;i++)
        {
            long long int x;
            cin >> x;
            vec.push_back(x);
        }

        long long int ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(((vec[i]+vec[j])%x==0)&&((abs(vec[i]-vec[j]))%y==0))
                {
                    // cout << vec[i] << " " << vec[j] << endl;
                    ans++;
                }
            }
        }

        cout << ans << endl;


        // find out the sum of array

        // long long int sum = 0;

        // for(auto it:vec)
        // {
        //     sum+=it;
        // }

        // if(n==1)
        // {
        //     cout << "YES" << endl;
        // }
        // else if(sum%n==0)
        // {
        //     long long int amount = sum/n;
        //     for(int i=n-1;i>0;i--)
        //     {
        //         if(vec[i]<amount)
        //         {
        //             vec[i-1]=vec[i-1]-(amount-vec[i]);
        //         }
        //     }

        //     if(vec[0]==amount)
        //     {
        //         cout << "YES" << endl;
        //     }
        //     else
        //     {
        //         cout << "NO" << endl;
        //     }
        // }
        // else
        // {
        //     cout << "NO" << endl;
        // }
    }
}