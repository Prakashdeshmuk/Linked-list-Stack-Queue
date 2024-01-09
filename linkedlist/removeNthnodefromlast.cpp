

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


int getlength(Node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        int length = 0;
        while(temp!=NULL)
        {
            temp = temp->next;
            length++;
        }
        return length;
    }
}

Node* removeKthNode(Node* head, int K)
{
    // if(head==NULL)
    // {
    //     return head;
    // }
    // int length = getlength(head);

    // int cnt = length-K;
    // if(cnt==0)
    // {
    //     head = head->next;
    //     return head;
    // }
    // Node *prev = NULL;
    // Node *curr = head;

    // while(cnt!=0)
    // {
    //     prev = curr;
    //     curr = curr->next;
    //     cnt--;

    // }
    // prev->next = curr->next;
    // curr->next = NULL;
    // delete curr;
    // return head;


    // approach two

    if(head==NULL)
    {
        return head;
    }

    Node *fast = head;
    Node *slow = head;
    for(int i=0;i<K;i++)
    {
        fast = fast->next;
    }

    if(fast==NULL)
    {
        return head->next;
    }

    while(fast->next!=NULL)
    {
        fast = fast->next ;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}

