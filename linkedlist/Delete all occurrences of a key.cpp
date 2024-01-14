/**
 * Definition of doubly linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * deleteAllOccurrences(Node* head, int k) {
    if((head==NULL)||(head->prev==NULL && head->next==NULL && head->data==k))
    {
        return NULL;
    }

    Node *temp = head;
    Node *dummy = new Node(-1);
    Node *res = dummy;

    while(temp!=NULL)
    {
        if(temp->data!=k)
        {
            res->next = temp;
            temp->prev = res;
            res = temp;

        }
        temp = temp->next;  
    }
    res->next = NULL;
    return dummy->next;
}
