//PROBLEM STATEMENT: https://leetcode.com/problems/same-tree/

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

/*------------------RECCURSIVE PREORDER TRAVERSAL----------------------------*/
class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q)
    {
        if(p==NULL && q!=NULL)
        {
            return false;
        }
        if(p==NULL || q==NULL)
        {
            return (p==q);
        }
        return (p->val==q->val) && helper(p->left, q->left) && helper(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        return helper(p, q);
    }
};