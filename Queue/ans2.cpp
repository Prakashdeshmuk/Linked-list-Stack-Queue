#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n,x;
    cin >> n >> x;

    int j = n/x;

    if(n%x==0)
    {
        cout << j << endl;
    }
    else{
        while(n%j!=0)
        {
            j--;
        }
        cout << j << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}