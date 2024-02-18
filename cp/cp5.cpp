#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll>vec;
        for(int i=0;i<2*n;i++)
        {
            ll x;
            cin >> x;
            vec.push_back(x);
        }


        for(int i=0;i<2*n;i++)
        {
            vec[i]=vec[i]+(i+1);
        }

        set<ll> st;

        sort(vec.begin(),vec.end());

        
    }
}