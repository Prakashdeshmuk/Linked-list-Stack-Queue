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

    int getlength(ListNode *head)
    {
        if(head==NULL)
        {
            return 0;
        }

        int length = 0;

        while(head!=NULL)
        {
            head = head->next;
            length++;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int actualr = k % getlength(head);
        if(actualr==0) return head;

        int cnt = getlength(head) - actualr-1;
        ListNode *lastNode = head;
        for(int i=0;i<cnt;i++)
        {
            lastNode = lastNode->next;
        }

        ListNode* newhead = lastNode->next;
        ListNode* ans = newhead;
        lastNode->next = NULL;
        cout << lastNode->val << endl;
        cout << newhead->val << endl;

        while(newhead->next!=NULL)
        {
            newhead = newhead->next;
        }
        cout << newhead->val << endl;
        newhead->next = head;
        return ans;
        
        
    }
};