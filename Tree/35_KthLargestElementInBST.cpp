//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/k-th-largest-number_920438?leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

TreeNode<int>* helper(TreeNode<int>* root, int& k) 
    {
        if(root==NULL)
        {
            return NULL;
        }    
        TreeNode<int>* right = helper(root->right, k); 
        if(right!=NULL)
        {
            return right;
        }
        k--;
        if(k==0)
        {
            return root;
        }
        return helper(root->left, k);
    }
int KthLargestNumber(TreeNode<int>* root, int k)
{
    TreeNode<int>* node = helper(root, k);
    if(node==NULL)
    {
        return -1;
    }
    return node->data;
}

