//PROBLEM STATEMENT : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

//--start leetcode 
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
    vector<vector<int>> helper(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false; //0 if true then 1
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level(size, 0);
            for(int i =0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                int ind = (!flag)?i:size-1-i;
                level[ind] = temp->val;
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
            flag=!flag;
            ans.push_back(level);
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return helper(root);
    }
};    //--end:Leetcode


//Zigzag Traversal : It is the way in which we can traverse the tree, in zigzag we traverse levelwise but in zigzag pattern.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
    public:
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<vector<int>> bfs(TreeNode<int>* node)
{
    vector<vector<int>> ans;
    if(node == NULL)
    {
        return ans;
    }
    queue<TreeNode<int>*> q;
    q.push(node);
    int flag = 0;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level(size, 0);
        for(int i =0; i<size; i++)
        {
            TreeNode<int>* temp = q.front();
            q.pop();
            int ind;
            if(flag==0)
            {
                ind = i;
            }
            else
            {
                ind = size-1-i;
            }
            level[ind] = (temp->data);
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->left!=NULL)
            {
                q.push(temp->right);
            }
        }
        if(flag==0)
        {
            flag = 1;
        }
        else{
            flag = 0;
        }
        ans.push_back(level);
    }
    return ans;
}
int main() 
{
    TreeNode<int>* n1 = new TreeNode<int>(1);
    n1->left = new TreeNode<int>(2);
    n1->right = new TreeNode<int>(3);
    vector<vector<int>> ans = bfs(n1);
    //printing the ans
    for(int i =0; i<ans.size(); i++)
    {
        for(int j =0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
