/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void santize(ListNode *head,unordered_map<int,ListNode*> &mp,int cSum)
    {
        int temp = cSum;
        while(true)
        {
            temp+=head->val;
            if(temp==cSum)
            {
                break;
            }
            mp.erase(temp);
            head = head->next;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head)
    {

        // if(head==NULL ||(head->next==NULL && head->val==0))
        // {
        //     return NULL;
        // }

        // unordered_map<int,ListNode*> mp;
        // auto it = head;
        // int cSum = 0;

        // while(it)
        // {
        //     cSum +=it->val;
        //     if(cSum==0)
        //     {
        //         head = it->next;
        //         mp.clear();
        //     }
        //     else if(mp.find(cSum)!=mp.end())
        //     {
        //         // map to santize karna hai 
        //         santize(mp[cSum]->next,mp,cSum);
        //         mp[cSum]->next = it->next;

        //     }
        //     else
        //     {
        //         mp[cSum] = it;
        //     }
        //     it = it->next;
        // }
        // return head;

        // approach two recursive approach 

        if(head==NULL)
        {
            return NULL;
        }

        ListNode *curr = head;
        int sum = 0;
        while(curr)
        {
            sum += curr->val;
            if(sum==0)
            {
                head = curr->next;
            }
            curr = curr->next;
        }
        if(!head) return head;
        head->next = removeZeroSumSublists(head->next);

        return head;
        
    }
};