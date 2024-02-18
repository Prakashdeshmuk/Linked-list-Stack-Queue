#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n,k;
    cin >> n >> k;

    string s,ans;
    char ch;

    for(int i=0;i<k;i++)
    {
        ch = ('a'+i);
        s = s+ch;
    }

    for(int i=0;i<n;i++)
    {
        ans+=s;
    }
    cout << ans << endl;
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