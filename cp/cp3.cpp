#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll check(vector<ll>vec,ll element)
{
    ll s=0;
    ll e = vec.size()-1;

    while(s<vec.size() && vec[s]==element)
    {
        s++;
    }

    while(e>=s && vec[e]==element)
    {
        e--;
    }
    return e-s+1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll>vec;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin >> x;
            vec.push_back(x);
        }


        cout << min(check(vec,vec[0]),check(vec,vec[n-1])) << endl;
    }
}