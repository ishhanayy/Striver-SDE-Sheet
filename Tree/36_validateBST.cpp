//PROBLEM STATEMENT : https://leetcode.com/problems/validate-binary-search-tree/

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

class Solution {
public:
    bool helper(TreeNode* root, long long min_range, long long max_range)
    {
        if(root==NULL)
        {
            return true;
        }
        if(root->val>=max_range || root->val<=min_range) //because the duplicates are not allowed in BST
        {
            return false;
        }
        return helper(root->left, min_range, root->val) && helper(root->right, root->val, max_range);
    }
    bool isValidBST(TreeNode* root) 
    {
        return helper(root, LONG_LONG_MIN, LONG_LONG_MAX);    
    }
};