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
        if(front==-1 && rear==-1)
        {
            cout << "Underflow" << endl;
            return;
        }
        else if(front==rear)
        {
            cout << arr[front] << " ";
            front = -1;
            rear = -1;

        }
        else
        {
            int temp = arr[front];

            front++;
            cout << "Deque Element" << temp << endl;
        }

        
    }

    void frontEle()
    {
       if(front==-1 && rear==-1)
       {
        cout << "Queue is Empty" << endl;
        return;
       }
       cout << arr[front] << " ";
       return;
    }


    void backEle()
    {
        if(front==-1 && rear==-1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << arr[rear] << " ";
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