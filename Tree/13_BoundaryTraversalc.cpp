//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/boundary-traversal_790725

//Boudary traversal will be in anticlockwise direction
#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <vector>
using namespace std;
bool isLeaf(TreeNode<int>* root) {
  if (!root) return false;
  if (!root->left && !root->right) return true;
  else return false;
}
void helperleft(TreeNode<int>* r, vector<int>& ans)
{
    TreeNode<int>* root = r->left;
    while(root)
    {
        if(!isLeaf(root))
        {
            ans.push_back(root->data);

        }
        if(root->left!=NULL)
        {
            root = root->left;
        }
        else 
        {
            root = root->right;
        }
    }
}
void helperLeaf(TreeNode<int>* root, vector<int>& ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left) helperLeaf(root->left, ans);
    if(root->right) helperLeaf(root->right, ans);
}
void helperRight(TreeNode<int>* r, vector<int>& ans)
{
    TreeNode<int>* root = r->right;
    vector<int> temp;
    while(root)
    {
        if(!isLeaf(root))
        {
            temp.push_back(root->data);
        }
        if(root->right!=NULL)
        {
            root  = root->right;
        }
        else{
            root = root->left;
        }
    }
    for(int i = temp.size()-1; i>=0; --i)
    {
        ans.push_back(temp[i]);
    }
}
vector<int> traverseBoundary(TreeNode<int>* root)
{
    vector<int> ans;
    if(!root)
    {
        return ans;
    }
    if(!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    helperleft(root, ans);
    helperLeaf(root, ans);
    helperRight(root, ans);
    return ans;
}
