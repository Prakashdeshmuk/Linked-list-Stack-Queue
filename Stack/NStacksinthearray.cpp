#include<iostream>
using namespace std;

class Nstack
{
    int *arr,*top,*next;

    int size,freespot;// size of the array
    int n; // Number of stack is to implemented 

    public:
    Nstack(int size,int n)
    {
        this->size = size;
        this-> n = n;
        this->freespot = 0;

        arr = new int[size];
        top = new int[n];
        next = new int [size];

        for(int i=0;i<n;i++)
        {
            top[i]=-1;
        }

        for(int i=0;i<n-1;i++)
        {
            next[i]=i+1;
        }
        next[n-1]=-1;
    }

    bool push(int X,int m)
    {
        if(freespot==-1)
        {
            cout << "Overflow" << endl;
            return false;
        }

        //1->find free spot 

        int index = freespot;

        //2->update free spot 

        freespot = next[index];

        //3->insert the Element on that index

        arr[index]=X;

        //4->find the next element top element in that particularb stack

        next[index]=top[m-1];

        //5->update the top element 

        top[m-1]=index;

        return true;
    }


    ~Nstack()
    {
        delete[] arr;
        delete[] top;
        delete[] next;
    }

    int pop(int m)
    {
        if(top[m-1]==-1)
        {
            cout << "underflow" << endl;
            return -1;
        }

        int index = top[m-1];

        top[m-1]=next[index];

        next[index]=freespot;


        return arr[index];


    }

    int getElement(int m)
    {
        if(top[m-1]==-1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top[m-1];
    }
    
};


int main()
{
    Nstack obj(6,3);

    cout << obj.push(10,1) << endl;
    cout << obj.push(11,1) << endl;
    cout << obj.pop(1) << endl;

    cout << obj.getElement(1) << endl;
    return 0;
}