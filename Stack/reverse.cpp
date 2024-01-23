#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 123;
    int i = 0;
    int ans = 0;
    while(n>0)
    {
        int digit = n%10;
        ans=ans*10+digit;
        i++;
        n = n/10;
    }
    cout << ans << " ";
    return 0;
}