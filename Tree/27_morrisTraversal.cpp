//PROBLEM STATEMENT : https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
        {
            return ans;
        }    
        TreeNode* temp = root;
        while(temp!=NULL)
        {
            if(temp->left==NULL) //if the left node is null then the root will be in the vector , inordered(roor, left, right)
            {
                ans.push_back(temp->val);
                temp = temp->right;
            }
            else
            {
                TreeNode* prev = temp->left;
                while(prev->right && prev->right!=temp)
                {
                    temp=temp->right;
                }
                if(prev->right==NULL)
                {
                    temp->right = temp;
                    temp = temp->left;
                }
                else if(prev->right == temp)
                {
                    prev->right = NULL;
                    ans.push_back(temp->val);
                    temp = temp->right;
                }
            }
        }
        return ans;
    }
};