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
    ListNode* reverse(ListNode *curr,ListNode *prev)
    {
        if(curr==NULL)
        {
            return prev;
        }
        ListNode *temp = curr->next ;
        curr->next = prev;
        prev = curr;
        curr = temp;
        return reverse(curr,prev);

    }

    int length(ListNode *head)
    {
        if(head==NULL)
        {
            return 0;
        }
        return 1+length(head->next);
    }

    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *newhead = reverse(curr,prev);

        stack<int> st;
        st.push(0);
        int size = length(newhead);
        vector<int> ans(size);

        while(newhead!=NULL)
        {
            int curr = newhead->val;
            while(st.top()!=0 && st.top()<=curr)
            {
                st.pop();
            }
            ans[size-1]=st.top();
            size--;
            st.push(curr);
            newhead = newhead->next;
        }
        return ans;

    }
};