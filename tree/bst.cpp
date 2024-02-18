#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertinbst(Node* root,int data)
{
    if(root==NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data>(root->data))
    {
        root->right = insertinbst(root->right,data);
    }
    else
    {
        root->left = insertinbst(root->left,data);
    }
    return root;
}

void takeinput(Node* &root)
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    while(data!=-1)
    {
        root = insertinbst(root,data);
        cin >> data;
    }
    return;
    
}


void levelOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size()>1)// which can !q.empty beacuse after each t
    {
        Node* front = q.front();
        q.pop();


        if(front==NULL)
        {
            // means one level is Complete 
            cout << endl;
            q.push(NULL);
        }
        else
        {
            cout << front->data << " ";

            if(front->left!=NULL)
            {
                q.push(front->left);
            }

            if(front->right!=NULL)
            {
                q.push(front->right);
            }

        }

       
    }

    return;
}


Node* minvalue(Node* root)
{
    if(root==NULL) return NULL;
    Node* temp = root;

    while(temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxvalue(Node* root)
{
    if(root==NULL) return NULL;
    Node* temp = root;
    while(temp->right)
    {
        temp = temp->right;
    }
    return temp;
}


Node* deleteFrombst(Node* root,int target)
{
    if(root==NULL) return root;


    if(root->data==target)
    {
        // 0 child case 
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        if(root->left!=NULL && root->right==NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }


        if(root->left==NULL && root->right!=NULL)
        {
            int mini = minvalue(root->right)->data;
            root->data = mini;
            root->right = deleteFrombst(root->right,mini);
            return root;
        }
        // 1 child case
        // 2 child case
    }
    else if(root->data>target)
    {
        root->left =deleteFrombst(root->left,target);
        return root;
    }
    else
    {
        root->right = deleteFrombst(root->right,target);
        return root;
    }

    return root;
}


bool Search(Node* root,int target)
{
    // if(root==NULL) return false;

    // if(root->data==target) return true;

    // if(root->data>target)
    // {
    //     return Search(root->left,target);
    // }
    // else
    // {
    //     return Search(root->right,target);
    // }



    // iterative approach
    Node* temp = root;

    while(temp!=NULL)
    {
        if(temp->data==target)
        {
            return true;
        }
        else if(temp->data>target)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}



// construct the balanced bst from inorder

Node* treeFrominorder(int inorder[],int start,int end)
{
    // base case

    if(start>end) return NULL;

    int mid =( start+end)/2;

    int element = inorder[mid];

    Node* root = new Node(element);

    root->left = treeFrominorder(inorder,start,mid-1);
    root->right = treeFrominorder(inorder,mid+1,end);


    return root;
}

Node* treefrompreorder(int preorder[],int start,int end)
{
    if(start>ed)
}



void convertBstSortedLL(Node* root,Node*&head)
{
    if(root==NULL) return;

    // right 
    convertBstSortedLL(root->right,head);

    root->right = head;

    if(head!=NULL)
    {
        head->left=root;
    }
    head = root;

    convertBstSortedLL(root->left,head);
}

void printLinkedList(Node* head)
{
    Node* temp = head;
    cout << "Printing the linked list" << endl;
    while(temp!=NULL)
    {
        cout << temp->data << "->";
        temp = temp->right;
    }
}


int main()
{


    // Node* root = NULL;

    // takeinput(root);

    // cout << "Printing Bst" << endl;
    // levelOrder(root);
    // cout << endl;
    // cout << "After Deleting Node" << endl;
    // root = deleteFrombst(root,30);
    // cout << "Printing Bst" << endl;
    // levelOrder(root);
    // cout << endl;
    // // making binary Search tree 

    // int target = 8;

    // bool ans = Search(root,target);

    // if(ans)
    // {
    //     cout << "Target is present In the bst" << endl;
    // }
    // else
    // {
    //     cout << "Target is Not part of the tree " << endl;
    // }
    

    int inorder[]={10,20,30,40,60,70,80};
    int size = 7;
    int start = 0;
    int end = size-1;

    Node* root = treeFrominorder(inorder,start,end);

    levelOrder(root);
    cout << endl;


    Node* head = NULL;
    convertBstSortedLL(root,head);
    printLinkedList(head);


}