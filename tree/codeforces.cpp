#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        string str = "abcdefghijklmnopqrstuvwxyz";


        string ans="";
        if(n>=3 && n<=28)
        {
            ans += "aa"+str.substr(n-3,1);
            cout << ans << endl;
        }
        else if(n>28 && n<=53)
        {
            ans+="a"+str.substr(n-28,1)+"z";
            cout << ans << endl;
        }
        else
        {
            ans+=str.substr(n-53,1)+"zz";
            cout << ans << endl;
        }

    }
}