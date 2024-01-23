#include<bits/stdc++.h>
using namespace std;

bool comp(int& a,int &b)
{
    return a>b;
}

int carFleet(int target, vector<int>& position, vector<int>& speed)
{
        vector<float>time;
        map<float,float>mapp;

        for(int i=0;i<position.size();i++)
        {
            mapp[position[i]]=speed[i];

        }
        for(auto it:mapp)
        {
            cout << it.first << "->" << it.second << endl;
            float CurrTime = (target-it.first)/it.second;
            time.push_back(CurrTime);
        }
        

        
        stack<float>st;

        for(auto it:time)
        {
            cout << it << " ";
        }

        for(auto it:time)
        {
            while(!st.empty() && it>=st.top())
            {
                st.pop();
            }
            st.push(it);
        }

        return st.size();


        
}

int main()
{
    int target = 12;
    vector<int>position={10,8,0,5,3};
    vector<int>speed ={2,4,1,1,3};

    int ans = carFleet(target,position,speed);

    cout << "Ans:" << ans << endl;
    return 0;
}