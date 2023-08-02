//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/right-view_764605?leftPanelTab=1

#include <queue>
#include <map>
/*************************************************************
 
    Following is the Binary Tree node structure:

    template <typename T>

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void helper(BinaryTreeNode<int>* root, int level, map<int, int>& m)
{  //preorder traversal in root, right, left
    if(root==NULL)
    {return;}
    if(m.find(level)==m.end())
    {
        m[level] = root->data;
    }
    helper(root->right, level+1, m);
    helper(root->left, level-1, m);
}
vector<int> printRightView(BinaryTreeNode<int>* root) 
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    int level = 0;
    map<int, int> m; 
    helper(root, level, m);
    for(auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}