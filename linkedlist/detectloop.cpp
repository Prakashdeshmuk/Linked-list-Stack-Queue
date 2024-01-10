/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // map<ListNode*,bool> mapp;

        // ListNode* temp = head;

        // while(temp!=NULL)
        // {
        //     if(mapp[head]==false)
        //     {
        //         mapp[head]=true;
        //     }
        //     else
        //     {
        //         return true;
        //     }
        //     temp = temp->next;
        // }
        // return false;


        // approach second 

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL)
        {
            fast = fast->next;
            if(fast!=NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            if(fast==slow)
            {
                return true;
            }
        }
        return false;
    }
};