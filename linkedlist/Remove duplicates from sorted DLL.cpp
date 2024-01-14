/**
 * Definition of doubly linked list:
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

Node * removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    // Node *dummy = new Node(-1);
    // Node *res = dummy;
    // Node *temp = head;
    // while(temp!=NULL)
    // {
    //     if(temp->next==NULL) break;
    //     if(temp->next->data!=temp->data)
    //     {
    //         res->next = temp;
    //         temp->prev = res;
    //         res = temp;
    //         temp = temp->next;
    //     }
    //     else
    //     {
    //         if(temp->next->next!=NULL)
    //         {
    //             Node *nextNode = temp->next->next;
    //             temp->next = nextNode;
    //             nextNode->prev = temp;
    //         }
    //         else
    //         {
    //             temp->next = NULL;

    //         }
    //     }
    // }
    // return dummy->next;

   // above approach failed one testcase

   Node *temp = head;
   while(temp!=NULL && temp->next!=NULL)
   {
       Node *nextNode = temp->next;
       while(nextNode!=NULL && temp->data==nextNode->data)
       {
           nextNode = nextNode->next;
       }
       temp->next = nextNode;
       if(nextNode!=NULL) nextNode->prev = temp;
       temp = temp->next;
   }
   return head;
}
