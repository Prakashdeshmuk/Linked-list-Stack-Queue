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

// void inorder(Node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }

//     //lrn

//     inorder(root->left);

//     cout << root->data << " ";

//     inorder(root->right);

    
// }



// void preorder(Node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }

//     cout << root->data << " ";

//     preorder(root->left);

//     preorder(root->right);
// }


// void postOrder(Node* root)
// {
//     if(root==NULL)
//     {
//         return;
//     }

//     postOrder(root->left);

//     postOrder(root->right);

//     cout << root->data << " ";
// }



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


//  int height(Node* node)
// {
//         if(node==NULL)
//         {
//             return 0;
//         }
        
//         int left = height(node->left);
//         int right = height(node->right);
        
//         return 1+max(left,right);
// }

//     // Function to return the diameter of a Binary Tree.
//     int diameter(Node* root) {
//         if(root==NULL)
//         {
//             return 0;
//         }
        
        
//         int option1 = diameter(root->left);
//         int option2 = diameter(root->right);
//         int option3 = height(root->left)+height(root->right)+1;
        
        
//         return max(max(option1,option2),option3);
//     }


//     Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
//         // we have two nodes p and q we have the lca of both of it 
//         if(root==NULL) return NULL;
//         if(root->val==p->val) return p;
//         if(root->val==q->val) return q;


//         Node* leftans = lowestCommonAncestor(root->left,p,q);
//         Node* rightans = lowestCommonAncestor(root->right,p,q);

//         if(leftans==NULL && rightans == NULL)
//         {
//             return NULL;
//         }
//         else if(leftans!=NULL && rightans==NULL)
//         {
//             return leftans;
//         }
//         else if(rightans!=NULL and leftans==NULL)
//         {
//             return rightans;
//         }
//         else
//         {
//             return root;
//         }

//     }

int findposition(int inorder[],int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(inorder[i]==element)
        {
            return i;
        }
    }
    return -1;
}    


// always keep in mind you have passed preindex by reference
// after each recursive preindex++ hota hai but we came back if you does not passed by reference it will same element Mutiple times 
Node* createTreefrompreorderandinorder(map<int,int>&mapp,int preorder[],int inorder[],int& preIndex,int inorderStart,int inorderEnd,int size)
{

    if(preIndex>=size || inorderStart>inorderEnd)
    {
        return NULL;
    }

    int element = preorder[preIndex];
    preIndex++;

    Node* root = new Node(element);


    // int position = findposition(inorder,size,element);
    int position = mapp[element];


    root->left =createTreefrompreorderandinorder(mapp, preorder,inorder,preIndex,inorderStart,position-1,size);

    root->right = createTreefrompreorderandinorder(mapp,preorder,inorder,preIndex,position+1,inorderEnd,size);

    return root;
}  

Node* createTreefrompostandinorder(int inorder[],int postorder[],int size,int &postindex,int inorderstart,int inorderend)
{
    if(postindex<0 || inorderstart>inorderend)
    {
        return NULL;
    }

    int element = postorder[postindex];
    postindex--;

    Node* root = new Node(element);

    int position = findposition(inorder,size,element);

    root->right = createTreefrompostandinorder(inorder,postorder,size,postindex,position+1,inorderend);

    root->left = createTreefrompostandinorder(inorder,postorder,size,postindex,inorderstart,position-1);

    return root;
}


void ksum(int& cnt ,vector<int>&path,Node* root,int k)
{
    if(root==NULL) return;

    path.push_back(root->data);


    ksum(cnt,path,root->left,k);
    ksum(cnt,path,root->right,k);

    int sum =0;
    for(int i=path.size()-1;i>=0;i--)
    {
        sum+=path[i];
        if(sum==k) cnt++;
    }
    path.pop_back();


}


Node* kthAncestor(Node* root,int &k,int target)
{
    if(root==NULL) return NULL;
    if(root->data==target) return root;

    Node* leftans = kthAncestor(root->left,k,target);
    Node* rightans = kthAncestor(root->right,k,target);

    if(leftans!=NULL && rightans==NULL)
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }
        return leftans;
    }

    if(leftans==NULL && rightans!=NULL)
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root;
        }
        return rightans;
    }

    return NULL;
}


pair<int,int>maxSum(Node* root)
{
    if(root==NULL)
    {
        pair<int,int> p = {0,0};
        return p;
    }


    auto left = maxSum(root->left);
    auto right = maxSum(root->right);


    pair<int,int>res;

    res.first = root->data + left.second + right.second;
    res.second = max(left.first,left.second)+max(right.first,right.second);

    return res;
}

Node* createmapping(map<Node*,Node*>&mapp,Node* root,int node)
{
    Node* targetNode = NULL;
    queue<Node*>qu;
    qu.push(root);
    mapp[root]=NULL;

    while(!qu.empty())
    {
        Node* front = qu.front();
        qu.pop();

        if(front->data==node)
        {
            targetNode = front;
        }

        if(front->left!=NULL)
        {
            mapp[front->left]=front;
            qu.push(front->left);
        }


        if(front->right)
        {
            mapp[front->right] = front;
            qu.push(front->right);
        }
    }

    return targetNode;
}


int burntree(Node* root,map<Node*,Node*>&mapp)
{
    int ans = 0;
    if(root==NULL) return ans;
    map<Node*,bool>visited;
    visited[root]=true;
    queue<Node*>qu;
    qu.push(root);

    while(!qu.empty())
    {
        int size = qu.size();
        bool flag = false;
        for(int i=0;i<size;i++)
        {
            // process Neighbouring Nodes

            Node* front = qu.front();
            qu.pop();

            if(front->left && !visited[front->left])
            {
                flag = true;
                qu.push(front->left);
                visited[front->left]=true;
            }


            if(front->right && !visited[front->right])
            {
                flag = true;
                qu.push(front->right);
                visited[front->right]= true;
            }


            if(mapp[front] && !visited[mapp[front]])
            {
                flag = true;
                qu.push(mapp[front]);
                visited[mapp[front]]=true;
            }
        }

        if(flag)
        {
            ans++;
        }
    }

    return ans;
}


bool validateBst(Node* root)
{
    if(root==NULL) return true;


    bool leftans = true;
    bool rightans = true;

    if(root->left)
    {
        leftans = (root->data)>(root->left->data);
    }


    if(root->right)
    {
        rightans = (root->data)<(root->right->data);
    }


    if(leftans && rightans)
    {
        return validateBst(root->left)&&validateBst(root->right);
    }
    else
    {
        return false;
    }

   


}



int main()
{
    // Node* root = createTree();
    // cout << root->data << endl;



    // preorder

    // cout << "Preoreder Traversal:" << " ";
    // preorder(root);
    // cout << endl;

    // cout << "Level Order :";

    // levelOrder(root);
    // return 0;

    // make tree from preorder and inorder
    // int preorder[]={2,8,10,6,4,2};
    // int inorder[] = {10,8,6,2,4,12};

    // int preindex = 0;
    // int inorderStart = 0;
    // int inorderEnd = 5;
    // int size = 6;

    // map<int,int> mapp;

    // for(int i=0;i<size;i++)
    // {
    //     mapp[inorder[i]]=i;
    // }

    // Node* root = createTreefrompreorderandinorder(mapp,preorder,inorder,preindex,inorderStart,inorderEnd,size);
    // cout << "Printing the tree" << endl;
    // levelOrder(root);


    // making tree from inorder and postorder

    // int inorder[]= {10,8,6,2,4,12};
    // int postorder[]={10,6,8,12,4,2};

    // int size = 6;
    // int postindex = size-1;
    // int inorderstart = 0;
    // int inorderend = size-1;

    // // map<int,int> mapp;

    // // for(int i=0;i<size;i++)
    // // {
    // //     mapp[inorder[i]]=i;
    // // }


    // Node* root = createTreefrompostandinorder(inorder,postorder,size,postindex,inorderstart,inorderend);
    // cout << "Printing the tree:" << endl;
    // levelOrder(root);

// k  sum path
    // int cnt = 0;
    // vector<int>path;
    // int k = 3;
    // Node* root = createTree();


    // ksum(cnt,path,root,k);
    // levelOrder(root);
    // cout << endl;
    // cout << "Total Number of Path:" << cnt << endl;


    // kth ancestor 

    // Node* root = createTree();

    // int k = 2;
    // int node = 4;

    // Node* ans = kthAncestor(root,k,node);

    // if(ans==NULL || ans->data==node)
    // {
    //     cout << "Ans:" << -1 << endl;
    // }
    // else
    // {
    //     cout << "Ans:"<< ans->data << endl;
    // }


    // maxisum sum by swapping Nodes

    // Node* root = createTree();
    // pair<int,int>ans = maxSum(root);

    // cout << "MaxiSum:" <<max(ans.first,ans.second) << endl;


    // maximum time to burn the tree 


    Node* root = createTree();

    int node = 8;

    // step1->create Node to parent mapping
    //step2->find that node in the tree 
    // step3->burn the tree 


    map<Node*,Node*>nodetoparent;

    Node* targetnode = createmapping(nodetoparent,root,node);


    // we have find minimum time to burn the tree

    int ans = burntree(targetnode,nodetoparent);


    cout << "Minimum Time to Burn the tree:" << ans << endl;



    
}