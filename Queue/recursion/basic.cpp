#include<bits/stdc++.h>
using namespace std;

void print(int a)
{
    if(a==10)
    {
        return;
    }

    cout << a << " ";
    print(++a);
}

void printName(int N,int cnt)
{
    if(cnt==N)
    {
        return;
    }

    cout << "Prakash" << " ";
    cnt++;
    printName(N,cnt);

}


void printNto1(int N)
{
    if(N==0)
    {
        return;
    }
    cout << N << " ";
    printNto1(--N);
}

void print1toN(int i,int N)
{
    if(i<1)
    {
        return;
    }

    print1toN(i-1,N);
    cout << i << " ";
}

void printAny(int i,int N)
{
    if(i>N)
    {
        return;
    }

    printAny(i+1,N);
    cout << i << " ";
}


void sum1(int i,int sum)
{
    if(i==0)
    {
        cout << sum;
        return;
    }
    sum1(i-1,sum+i);
}

int sum2(int N)
{
    if(N==0)
    {
        return 0;
    }
    return N+sum2(N-1);
}

void reverse(vector<int>&vec,int i,int j)
{
    if(i>j)
    {
        return;
    }
    swap(vec[i],vec[j]);
    i++;
    j--;
    reverse(vec,i,j);
}

int ntnFib(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    return ntnFib(n-1)+ntnFib(n-2);
}
int main()
{
    // int a = 1;
    // print(a);

    // print Name n times

    int N = 5;
    int cnt = 0;

    // printName(N,cnt);

    // printNto1(N);

    // printAny(1,N);


    // basic recursion problems 
    //1->print N to 1
    //print name N times

    //types of recusrion 
    //1->functional recursion
    //2->parameterized recusrion

    // lets is understand with simple example 

    // sum1(3,0);//this parameterized recurssion

    // second functional way 
    // there is golden line
    // ek case me solve karguna baki recusrion sambhal lenge

    // cout << sum2(3);

    //reverse array
    // vector<int> arr={1,2,3,4,5,6};
    // int i = 0;
    // int j = arr.size()-1;
    // reverse(arr,i,j);

    // for(auto it:arr)
    // {
    //     cout << it << " ";
    // }


    cout << ntnFib(6);

}