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

//use of BFS
//Width of Binary Tree : The Width of the tree is the maximum num of nodes present of the level between two nodes. (Note: There Must be Present Start and the End Node)

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return 0;
        }
        int width =0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            int ind = q.front().second; 
            int fi, ei; 
            for(int i =0; i<size; i++)
            {
                int curr_ind = q.front().second-ind;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i==0){fi = curr_ind;}
                if(i==size-1){ei = curr_ind;}
                if(temp->left!=NULL)
                {
                    q.push({temp->left, curr_ind*2+1});
                }
                if(temp->right!=NULL)
                {
                    q.push({temp->right, curr_ind*2+2});
                }
            }
            width = max(width, ei-fi+1);
        }
        return width;
    }
};