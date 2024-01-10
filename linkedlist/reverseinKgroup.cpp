class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        if(head==NULL)
        {
            return NULL;
        }
        
        node *current = head;
        node *next = NULL;
        node *prev = NULL;
        
        int cnt = 0;
        while((current!=NULL)&&(cnt<k))
        {
            cnt++;
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        if(next!=NULL)
        {
            node *ans =reverseIt (current,k);
            head->next = ans;
            
        }
        
        return prev;
    }
};