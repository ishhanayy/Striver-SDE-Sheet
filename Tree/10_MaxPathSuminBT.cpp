//PROBLEM STATEMENT : https://leetcode.com/problems/maximum-width-of-binary-tree/

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


/*----------Use of Backtracking-----------------*/
class Solution {
public:
    int helper(TreeNode* root, int& maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = max(0, helper(root->left, maxi));
        int right = max(0, helper(root->right, maxi));
        maxi = max(maxi, left+right+root->val);
        return root->val+max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1e9;
        helper(root, maxi);
        return maxi;
    }
};