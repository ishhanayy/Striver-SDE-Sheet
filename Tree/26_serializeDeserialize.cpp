//PROBLEM STATMENT : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root==NULL)
        {
            return "";
        }    
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL)
            {
                ans.append("#,");
            }
            else
            {
                ans.append(to_string(temp->val)+',');
            }
            if(temp!=NULL)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.size()==0)
        {
            return NULL;
        }    
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            getline(ss, str, ',');
            if(str=="#")
            {
                temp->left = NULL;
            }
            else
            {
                TreeNode* templeft = new TreeNode(stoi(str));
                temp->left = templeft;
                q.push(templeft);
            }
            getline(ss, str, ',');
            if(str=="#")
            {
                temp->right = NULL;
            }
            else
            {
                TreeNode* tempRight = new TreeNode(stoi(str));
                temp->right = tempRight;
                q.push(tempRight);
            }
        }
        return root;
    }
};