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
    ListNode* solution(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }

        ListNode *start = head;
        start = start->next;
        ListNode *dummy = new ListNode();
        int sum = 0;
        while(start->val!=0 && start!=NULL)
        {
            sum +=start->val;
            start = start->next;
        }
        ListNode *newNode = new ListNode(sum);
        dummy->next = newNode;
        ListNode *ans = solution(start);
        newNode->next = ans;
        return newNode;
    }
    ListNode* mergeNodes(ListNode* head) {
        return solution(head);
    }
};