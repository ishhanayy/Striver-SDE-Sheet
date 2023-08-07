//PROBLEM STATEMENT : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* helper(vector<int>& inorder, int ii, int ie, vector<int>& postorder, int pi, int pe, map<int, int>& m)
    {
        if(pi>pe || ii>ie)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pe]);
        int inroot = m[postorder[pe]];
        int num_left = inroot-ii;
        root->left = helper(inorder, ii, inroot-1, postorder, pi, pi+num_left-1, m);
        root->right = helper(inorder, inroot+1, ie, postorder, pi+num_left, pe-1, m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        map<int, int> m;
        for(int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, m);    
    }
};