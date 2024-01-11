
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:

    ListNode* findmid(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next!=NULL)
        {
            fast = fast->next;
            if(fast->next!=NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* left = list1;
        ListNode* right = list2;

        if((left==NULL)&&(right==NULL))
        {
            return NULL;
        }

        if(left==NULL)
        {
            return right;
        }

        if(right==NULL)
        {
            return left;
        }

        ListNode* dummy = new ListNode();
        ListNode* newhead = dummy;

        while((left!=NULL)&&(right!=NULL))
        {
            if((left->val)<=(right->val))
            {
                ListNode* newNode = new ListNode(left->val);
                dummy->next = newNode;
                left = left->next;
                dummy = newNode;
            }
            else
            {
                ListNode* newNode = new ListNode(right->val);
                dummy->next = newNode;
                right = right->next;
                dummy = newNode;
            }
        }

        while(left!=NULL)
        {
                ListNode* newNode = new ListNode(left->val);
                dummy->next = newNode;
                left = left->next;
                dummy = newNode;
        }

        while(right!=NULL)
        {
                ListNode* newNode = new ListNode(right->val);
                dummy->next = newNode;
                right = right->next;
                dummy = newNode;
        }

        return newhead->next;
        
    }
    ListNode* sortList(ListNode* head) 
    {
        if((head==NULL)||(head->next==NULL))
        {
            return head;
        }

        // find the mid

        ListNode* mid = findmid(head);

        ListNode* left = head;
        ListNode* right = mid->next;

        mid->next = NULL;

        left =sortList(left);
        right = sortList(right);

        return mergeTwoLists(left,right);



        
    }
};