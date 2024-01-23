#include<bits/stdc++.h>
using namespace std;


class Queue
{
    int front,rear;
    int *arr;
    int size_;

    public:

    Queue(int size_)
    {
        this->size_ = size_;
        front = -1;
        rear = -1;
        arr = new int[size_];
    }


    void enqueue(int ele)
    {
        if(rear==size_-1)
        {
            cout << "Overflow" << endl;
            return;
        }

        if(front==-1)
        {
            front++;
        }

        rear++;

        arr[rear]=ele;
    }

    void deque()
    {
        if(front==-1 || front>rear)
        {
            cout << "Underflow" << endl;
            return;
        }

        int temp = arr[front];

        front++;
        cout << "Deque Element" << temp << endl;
    }

    void frontEle()
    {
       if(front==-1 || front>rear)
       {
            cout << "No Elements In the Queue" << endl;
            return;
       }
       cout << arr[front] << " ";
    }



};

int main()
{
    Queue qu(5);
    qu.enqueue(10);
    qu.enqueue(20);
    qu.deque();
    qu.deque();
    qu.frontEle();

}