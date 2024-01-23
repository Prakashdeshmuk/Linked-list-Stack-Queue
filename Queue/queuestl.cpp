#include<bits/stdc++.h>
using namespace std;

int main()
{

    queue<int> qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop();
    qu.pop();
    qu.pop();
    cout << qu.front() << endl;
    cout << qu.back() << endl;

    if(qu.empty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is Not Empty" << endl;
    }

    cout << qu.size() << endl;
    return 0;
}