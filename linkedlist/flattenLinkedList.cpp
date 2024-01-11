Node *merge(Node *list1,Node *list2)
{
    if((list1==NULL)&&(list2==NULL))
    {
        return NULL;
    }
    
    if(list1==NULL)
    {
        return list2;
    }
    
    if(list2==NULL)
    {
        return list1;
    }
    
    Node *left = list1;
    Node *right = list2;
    Node *ans = NULL;
    if(left->data<right->data)
    {
        ans = left;
        left->bottom = merge(left->bottom,right);
    }
    else
    {
        ans = right;
        right->bottom = merge(left,right->bottom);
    }
    return ans;
}
Node *flatten(Node *root)
{
   if(root==NULL)
   {
       return NULL;
   }
   
   return merge(root,flatten(root->next));
}