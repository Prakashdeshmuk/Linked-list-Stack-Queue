/****************************************************************

    Following is the class structure of the Node class:

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

*************************************************************
****/

Node *reverse(Node *prev,Node  *curr)
{
    if(curr==NULL)
    {
        return prev;
    }

    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;

    return reverse(prev,curr);
}

bool isPalindrome(Node *head)
{
    if (head==NULL)
    {
        return true;
    }

    // vector<int> arr;
    // Node *temp = head;
    // while(temp!=NULL)
    // {
    //     arr.push_back(temp->data);
    //     temp = temp->next;
    // }

    // for(int i=0;i<arr.size()/2;i++)
    // {
    //     if(abs(arr[i])!=abs(arr[arr.size()-i-1]))
    //     {
    //         return false;
    //     }
    // }
    // return true;

    // approach 2

    Node *fast = head;
    Node *slow = head;
    while(fast->next!=NULL)
    {
        fast = fast->next;
        if(fast->next!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    
    Node *curr = slow->next;
    Node *prev = NULL;
    Node *head2 = reverse( prev, curr);
    
    slow->next = NULL;
    while((head!=NULL)&&(head2!=NULL))
    {
        if(abs(head->data)!=abs(head2->data))
        {
            return false;
        }
        head=head->next;
        head2 = head2->next;
    }
    return true;
}