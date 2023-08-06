//PROBLEM STATEMENT : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    TreeNode* helper(TreeNode* root, int& k) 
    {
        if(root==NULL)
        {
            return NULL;
        }    
        TreeNode* left = helper(root->left, k); 
        if(left!=NULL)
        {
            return left;
        }
        k--;
        if(k==0)
        {
            return root;
        }
        return helper(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k)
    {
        TreeNode* node = helper(root, k);
        if(node==NULL)
        {
            return 0;
        }
        return node->val;
    }
};