#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }


};


Node* createTree()
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;

    if(data==-1)
    {
        return NULL;
    }

    // create a Node

    Node* root = new Node(data);
    cout << "Enter The left for root " << root->data << endl; 
    root->left = createTree();
    cout << "Enter the Right Element of the root" << root->data << endl;
    root->right = createTree();

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    //lrn

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);

    
}



void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);

    preorder(root->right);
}


void postOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    postOrder(root->left);

    postOrder(root->right);

    cout << root->data << " ";
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


// leftview of binary tree
void solve(vector<int>&ans,int level,Node* root)
{
    if(root==NULL) return;
    
    if(level==ans.size())
    {
        ans.push_back(root->data);
    }
    
    solve(ans,level+1,root->left);
    solve(ans,level+1,root->right);
}

vector<int> leftView(Node *root)
{
   vector<int>ans;
   solve(ans,0,root);
   return ans;
}



// right view of binary tree 
void solve1(Node* root,vector<int>&ans,int level)
    {
        if(root==NULL) return;
        if(ans.size()==level)
        {
            ans.push_back(root->data);
        }
        
        solve1(root->right,ans,level+1);
        solve1(root->left,ans,level+1);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int>ans;
       int level = 0;
       solve1(root,ans,level);
       return ans;
    }


    // top view of binary tree 
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,int>mapp;
        // we have traveerse it by level wise so make queue for it 
        queue<pair<Node*,int>> qu;
        // node respresent the current node 
        // the pair second represent the node level
        
        qu.push(make_pair(root,0));
        
        while(!qu.empty())
        {
            pair<Node*,int> p = qu.front();
            qu.pop();
            
            Node* node = p.first;
            int hd = p.second;
            
            if(mapp.find(hd)==mapp.end())
            {
                mapp[hd]=node->data;
            }
            
            if(node->left!=NULL)
            {
                qu.push(make_pair(node->left,hd-1));
            }
            
            if(node->right!=NULL)
            {
                qu.push(make_pair(node->right,hd+1));
            }
        }
        
        
        for(auto it:mapp)
        {
            ans.push_back(it.second);
        }
        return ans;
        
        
    }

    // bottom view of binary tree 
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int>mapp;
        // we have traveerse it by level wise so make queue for it 
        queue<pair<Node*,int>> qu;
        // node respresent the current node 
        // the pair second represent the node level
        
        qu.push(make_pair(root,0));
        
        while(!qu.empty())
        {
            pair<Node*,int> p = qu.front();
            qu.pop();
            
            Node* node = p.first;
            int hd = p.second;
            
           
            mapp[hd]=node->data;
            
            if(node->left!=NULL)
            {
                qu.push(make_pair(node->left,hd-1));
            }
            
            if(node->right!=NULL)
            {
                qu.push(make_pair(node->right,hd+1));
            }
        }
        
        
        for(auto it:mapp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }


    // boundry traversal


    void printleftboundry(Node* root)
    {
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL)
        {
            return;
        }

        cout << root->data << " ";

        if(root->left!=NULL)
        {
            printleftboundry(root->left);
        }
        else
        {
            printleftboundry(root->right);
        }
    }


    void printrightboundry(Node* root)
    {
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL)
        {
            return;
        }

        

        if(root->right!=NULL)
        {
            printrightboundry(root->right);
        }
        else
        {
            printrightboundry(root->left);
        }
        cout << root->data << " ";
    }


    void printleaves(Node* root)
    {
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL)
        {
            cout << root->data << " ";
        }

        printleaves(root->left);
        printleaves(root->right);
    }


    void boundry(Node* root)
    {
        if(root==NULL) return;

        cout << root->data << " ";
        printleftboundry(root->left);
        printleaves(root->left);
        printleaves(root->right);
        printrightboundry(root->right);
        
    }








int main()
{
    Node* root = createTree();
    // cout << "printing level order" << endl;
    // levelOrder(root);

    cout << "Priting boundry traversal" << " "  << endl;
    boundry(root);
    return 0;
}