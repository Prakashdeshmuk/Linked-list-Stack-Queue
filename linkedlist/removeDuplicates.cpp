Node *removeDuplicates(Node *head)
{
    
    if(head==NULL)
    {
        return head;
    }
    
    if(head->next==NULL)
    {
        return head;
    }
    
    Node *temp = head;
    Node *NextNode = NULL;
    
    while(temp->next!=NULL)
    {
        Node *newNode = temp->next;
        if(temp->data==newNode->data)
        {
            NextNode = newNode->next;
            newNode->next = NULL;
            temp->next = NextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}