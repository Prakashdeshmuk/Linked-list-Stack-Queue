

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


Node* sortList(Node *head){
    // int ZeroCnt=0,OneCnt=0,TwoCnt=0;

    // Node *temp = head;
    // while(temp!=NULL)
    // {
    //     if(temp->data == 0)
    //     {
    //         ZeroCnt++;
    //     }
    //     else if(temp->data ==1)
    //     {
    //         OneCnt++;
    //     }
    //     else
    //     {
    //         TwoCnt++;
    //     }
    //     temp = temp->next;
    // }

    // Node *dummyHead = new Node();
    // Node *temp2 = dummyHead;

    // while(ZeroCnt!=0)
    // {
    //     Node *newNode = new Node(0);
    //     temp2->next = newNode;
    //     temp2 = newNode;
    //     ZeroCnt--;
    // }
    // while(OneCnt!=0)
    // {
    //     Node *newNode = new Node(1);
    //     temp2->next = newNode;
    //     temp2 = newNode;
    //     OneCnt--;
    // }
    // while(TwoCnt!=0)
    // {
    //     Node *newNode = new Node(2);
    //     temp2->next = newNode;
    //     temp2 = newNode;
    //     TwoCnt--;
    // }
    // return dummyHead->next;

    // approach two 


    Node *dummyone = new Node();
    Node *dummytwo = new Node();
    Node *dummyzero = new Node();

    Node *temp = head;
    Node *newNode = NULL;
    head = dummyzero;
    Node *secondhead = dummyone;
    Node *thirdhead = dummytwo;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            newNode = new Node(0);
            dummyzero->next = newNode;
            dummyzero = newNode;
        }
        else if(temp->data==1)
        {
            newNode = new Node(1);
            dummyone->next = newNode;
            dummyone = newNode;
        }
        else
        {
            newNode = new Node(2);
            dummytwo->next = newNode;
            dummytwo = newNode;
        }
        temp = temp->next;
    }
    dummyzero->next = secondhead->next;
    dummyone->next = thirdhead->next;
    return head->next;


}