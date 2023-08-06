//PROBLEM STATEMENT : https://leetcode.com/problems/search-in-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Binary Search Tree : In the binary search tree, the left node is always less then the root, and the root is always greater then the right.
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int data) 
    {
        if(root==NULL)
        {
            return NULL;
        }    
        TreeNode* temp = root;
        while(temp!=NULL)
        {
            if(temp->val == data)
            {
                return temp;
            }
            else if(temp->val>data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return NULL;
    }
};