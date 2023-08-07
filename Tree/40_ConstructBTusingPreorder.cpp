//PROBLEM STATEMENT : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* helper(vector<int>& po, int& i, int ub)
    {
        if(i==po.size() || po[i]>ub)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(po[i++]);
        root->left = helper(po, i, root->val);
        root->right = helper(po, i, ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        int i = 0;
        return helper(preorder, i, INT_MAX);
    }
};