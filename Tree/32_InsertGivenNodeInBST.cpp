//PROBLEM STATEMENT : https://leetcode.com/problems/insert-into-a-binary-search-tree/

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


//Recursive
class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode*& node)
    {
        if(root==NULL)
        {
            return node;
        }
        if(root->val<node->val)
        {
            root->right = helper(root->right, node);
        }
        else
        {
            root->left = helper(root->left, node);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        TreeNode* node = new TreeNode(val);
        return helper(root, node);    
    }
};


//Iterative (striver)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int data) 
    {
        TreeNode* node = new TreeNode(data);
        if(root==NULL)
        {
            return node;
        }
        TreeNode* temp = root;
        while(true)
        {
            if(temp->val<data)
            {
                if(temp->right!=NULL)
                {
                    temp = temp->right;
                }
                else
                {
                    temp->right = node;
                    break;
                }
            }
            else
            {
                if(temp->left!=NULL)
                {
                    temp = temp->left;
                }
                else
                {
                    temp->left = node;
                    break;
                }
            }
        }
        return root;
    }
};