#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Destructor called" << endl;
        cout << this->data << endl;
    }
};


void printLL(Node* head)
{
    int length = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        length++;
        
    }
    // cout << "Length" << length << endl;
}


void insertAthead(Node* &head,Node*& tail,int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail=newNode;
        // is empty empty singly linked list than head and tail are at the same position
    }
    else
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    
}

void insertAttail(Node* & head,Node* & tail,int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else
    {
        Node* newNode = new Node(data);
        tail->next =newNode;
        tail=newNode;
    }
}

int getlength(Node* head)
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        Node* temp = head;
        int length = 0;
        while(temp!=NULL)
        {
            temp=temp->next;
            length++;
        }
        return length;
    }
}

void insertAtanyposition(Node* &head , Node* & tail,int data ,int position)
{
    
    int length = getlength(head);
    if(position<=1)
    {
       insertAthead(head,tail,data); 
    }
    else if(position>length)
    {
        insertAttail(head,tail,data);
    }
    else
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* temp = new Node(data);
        
        while(position!=1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = temp;
        temp->next = curr;
    }
}

void deletion(Node* & head,Node*&tail,int position)
{
    // 1->if linked list is Empty
    if(head==NULL)
    {
        cout << "Cannot delete element from the linked list";
        return;
    }
    
    if(head==tail)
    {
        //this is case of singl element 
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    int length = getlength(head);

    if(position==1)
    {
        // to delete the element from the head of linked list 
        // Node* temp = head->next;
        // head->next = NULL;
        // head = temp;

        // 2-> way

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        
    }
    else if(position==length)
    {
        Node* temp = head;
        while((temp->next)->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    else
    {
        Node* prev = NULL;
        Node* curr = head;

        while(position!=1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    // Node* first = new Node(15);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);

    
    // first->next= second;
    // second->next = third;
    // third->next = fourth;

    // Node* head = first;
    // Node* tail = fourth;
    // printLL(head);
    // cout << endl;
    // insertAthead(head,tail,60);// we insert 60 at head and 90 at the tail of the linked list
    // insertAttail(head,tail,90);
    Node* head = NULL;
    Node* tail = NULL;
    
    insertAthead(head,tail,30);
    // insertAthead(head,tail,40);
    // insertAthead(head,tail,60);
    // insertAttail(head,tail,90);
    // insertAtanyposition(head,tail,110,3);
    deletion(head,tail,1);
    printLL(head);
    return 0;
}