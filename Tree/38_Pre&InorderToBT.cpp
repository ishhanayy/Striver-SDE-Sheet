//PROBLEM STATEMENT : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    TreeNode* helper(vector<int>& preorder, int pi, int pe, vector<int>& inorder, int ii, int ie, map<int, int>& m)
    {
        if(pi>pe || ii>ie)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pi]);
        int inroot = m[preorder[pi]];
        int numsleft = inroot - ii;
        root->left = helper(preorder, pi+1, pi+numsleft, inorder, ii, inroot-1, m);
        root->right = helper(preorder, pi+numsleft+1, pe, inorder, inroot+1, ie, m);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int inStart = 0;
        int inEnd = inorder.size()-1;
        int preStart = 0;
        int preEnd = preorder.size()-1;    
        map<int, int> inPlace; //it will store the position of the node in the inorder
        for(int i = 0; i<inorder.size(); i++)
        {
            inPlace[inorder[i]] = i;
        }

        return helper(preorder, preStart, preEnd, inorder, inStart, inEnd, inPlace);
    }
};