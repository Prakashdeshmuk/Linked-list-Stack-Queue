#include<iostream>
using namespace std;


class cQueue
{
    public:
    int front,rear,size;
    int *arr;

    cQueue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }


    void push(int ele)
    {
        //1->overflow
        //2->first element case
        //3->circular wali case
        // 4->Normal Case

        if((front==-1 && rear==size-1) ||(rear+1==front))
        {
            cout << "Overflow" << endl;
        }
        else if(front==-1 && rear==-1)
        {
            front++;
            rear++;
            arr[rear]=ele;
        }
        else if(rear==size-1 && front!=0)
        {
            rear = 0;
            arr[rear]=ele;
        }
        else
        {
            rear++;
            arr[rear]=ele;
        }
    }


    void pop()
    {
        //1->underflow
        //2->first  Element case
        //3->circular case
        //4->Normal case

        if(front==-1)
        {
            cout << "Underflow" << endl;
        }
        else if(front==rear)
        {
            arr[front]=-1;
            front = -1;
            rear = -1;
        }
        else if(front==size-1)
        {
            arr[front]=-1;
            front = 0;
        }
        else
        {
            arr[front]=-1;
            front++;
        }

    }

    void print()
    {
        cout << "Printing Queue" << endl;
        for(int i=0;i<size;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cQueue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.pop();
    q.pop();
    q.push(30);
    q.push(20);
    q.push(100);
    q.print();
    return 0;
}