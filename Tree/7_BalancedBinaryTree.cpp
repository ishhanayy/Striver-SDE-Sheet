//PROBLEM STATEMENT : https://leetcode.com/problems/balanced-binary-tree/


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


/*---------------------RECCURSIVE---------------------*/
class Solution {
public:
    int helper(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int h1 = helper(root->left);
        if(h1==-1)
        {
            return -1;
        }
        int h2 = helper(root->right);
        if(h2==-1)
        {
            return -1;
        }
        if(abs(h1-h2)>1)
        {
            return -1;
        }
        return max(h1, h2)+1;
    }
    bool isBalanced(TreeNode* root) 
    {
        //Balanced Binary Tree : If in any Tree height(left)-height(right)<=1 then it is Balanced Binary Tree.
        int ans = helper(root); 
        if(ans==-1)
        {
            return false;
        }   
        else 
        {
            return true;
        }
    }
};
