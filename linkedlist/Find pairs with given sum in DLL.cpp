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
 *          this -> data = data;
 *          this -> prev = prev;
 *          this -> next = next;
 *      }
 * };
 *
 *************************************************************************/
int getlength(Node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    return 1+getlength(head->next);
}
vector<pair<int, int>> findPairs(Node* head, int k)
{
    Node *ptr1 = head;
    Node *ptr2 = head;
    while(ptr2->next!=NULL)
    {
        ptr2 = ptr2->next;
    }
    int cnt1 = 1;
    int cnt2 = getlength(head);
    vector<pair<int,int>>ans;

    while(cnt1<cnt2)
    {
        if((ptr1->data)+(ptr2->data)==k)
        {
          pair<int, int> pair (ptr1->data,ptr2->data);
          ans.push_back(pair);
          ptr1 = ptr1->next;
          ptr2 = ptr2->prev;
          cnt1++;
          cnt2--;
        }
        else if((ptr1->data)+(ptr2->data)>k)
        {
            ptr2 = ptr2->prev;
            cnt2--;
        }
        else
        {
            ptr1 = ptr1->next;
            cnt1++;
        }
    }
    return ans;



}
