#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Destructor is called for ->" << this->data << endl;
    }

};

void printLL(Node* & head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int getlength(Node* & head)
{
    Node* temp = head;
    int length = 0;
    while(temp!=NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAthead(Node* & head,Node* & tail,int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;

    }
    else 
    {
        Node* temp = new Node(data);
        head->prev = temp;
        temp->next = head;
        head = temp;
        return;
    }
}

void insertAttail(Node* & head,Node* & tail,int data)
{
    if(tail==NULL)
    {
        // LL is empty
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    else
    {
        Node* temp = new Node(data);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        return; 
    }
}

void insertAtanyposition(Node* & head,Node* & tail,int data,int position)
{
    int length = getlength(head);

    if(position==1)
    {
        insertAthead(head,tail,data);
    }
    else if(position>length)
    {
        insertAttail(head,tail,data);
    }
    else 
    {
        Node* temp = new Node(data);

        Node* prevNode = NULL;
        Node* curr = head;

        while(position!=1)
        {
            prevNode = curr;
            curr = curr->next;
            position--;
        }

        prevNode->next = temp;
        temp->prev = prevNode;
        temp->next = curr;
        curr->prev = temp;
        return;

    }
}

void deletionAthead(Node* & head,Node* & tail)
{
    if(head==NULL)
    {
        cout << "You cannot delete the Element from the Linked list" << endl;
    }
    else
    {
       Node* newNode = head;
       head = head->next;
       newNode->next = NULL;
       head->prev = NULL;
       delete newNode;

    }
}

void deletionAttail(Node* & head,Node* & tail)
{
    if(tail==NULL)
    {
        cout << "Cannot Delete Element from the Linked list" << endl;
    }
    else
    {
        Node* newNode = tail;
        tail = tail->prev;
        newNode->prev = NULL;
        tail->next = NULL;
        delete newNode;
    }
}

void DeleteAtanyPosition(Node* & head,Node* & tail,int position)
{
    int length = getlength(head);
    if(position==1)
    {
        deletionAthead(head,tail);
    }
    else if(position>=length)
    {
        deletionAttail(head,tail);
    }
    else
    {
        Node* prevNode = NULL;
        Node* curr = head;

        while(position!=1)
        {
            position--;
            prevNode = curr;
            curr = curr->next;
        }

        Node* newNode = curr->next;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        delete curr;

    }
    
}

Node *makedoubley(int arr[4])
{
    int size = 4;

    Node *head = new Node(arr[0]);
    Node *curr = head;

    for(int i=1;i<size;i++)
    {
        Node *newNode = new Node (arr[i]);
        newNode->prev = curr;
        curr->next = newNode;
        curr = newNode;
    }
    return head;
}


int main()
{
    // Node* head = NULL;
    // Node* tail = NULL;

    // insertAthead(head,tail,20);
    // insertAthead(head,tail,30);
    // insertAthead(head,tail,40);
    // insertAthead(head,tail,60);
    // insertAttail(head,tail,90);
    
    // printLL(head);
    // cout << endl;
    // // insertAtanyposition(head,tail,1000,5);
    // // printLL(head);
    // DeleteAtanyPosition(head,tail,5);
    // cout << endl;
    // printLL(head);


    // question 1-> make doubly linked list from the array

    int arr[4] ={4,2,3,1};

    // function will return head of the doubly Linked list 

    Node *head = makedoubley(arr);

    printLL(head);


    return 0;

}