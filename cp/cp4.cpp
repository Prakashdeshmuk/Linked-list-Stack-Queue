#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


void solve(ll k,ll x ,ll a)
{
        if(x>=a)
        {
            cout << "NO" << endl;
            return;
        }

        if(k>x+1)
        {
            cout << "YES" << endl;
            return;
        }


        ll used = 0;
        for(int i=0;i<=x;i++)
        {
            ll bet = (used/(k-1))+1;
            used+=bet;
            if(used>a)
            {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll k,x,a;
        cin >> k >> x >> a;
        solve(k,x,a);   
    }
}