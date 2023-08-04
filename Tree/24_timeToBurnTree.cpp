/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/time-to-burn-tree_630563?leftPanelTab=0

#include <map>
void ParentTrack(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& pt)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int>* temp = q.front();
        q.pop();
        if(temp->left)
        {
            pt[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            pt[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

BinaryTreeNode<int>* traversal(BinaryTreeNode<int>* root, int target)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==target)
    {
        return root;
    }
    BinaryTreeNode<int>* left = traversal(root->left, target);
    if(left)
    {
        return left;
    }
    return traversal(root->right, target);
}

int helper(BinaryTreeNode<int> *root, int start) {
    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> pt;
    ParentTrack(root, pt);
    BinaryTreeNode<int>* node = traversal(root, start);
    queue<BinaryTreeNode<int>*> q;
    map<BinaryTreeNode<int>*, bool> visited;
    int time = -1; // it is doing the work at time zero, from time 0 it will start burning 
    q.push(node);
    visited[node] = true;
    while(!q.empty())
    {
        int size = q.size();
        time+=1;
        for(int i =0;i<size; i++)
        {
            BinaryTreeNode<int>* temp = q.front();
            q.pop();
            if(temp->left && !visited[temp->left])
            {
                q.push(temp->left);
                visited[temp->left] = true;
            }
            if(temp->right && !visited[temp->right])
            {
                q.push(temp->right);
                visited[temp->right] = true;
            }
            if(pt[temp] && !visited[pt[temp]])
            {
                q.push(pt[temp]);
                visited[pt[temp]] = true;
            }
        }
        
    }
    return time;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    return helper(root, start);
}
