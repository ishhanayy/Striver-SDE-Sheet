//PROBLEM STATEMENT : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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

#include <vector>
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, multiset<int>>> store; //multiset can contain duplicate numbers
        queue <pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while(!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            TreeNode* temp = p.first;
            int x = p.second.first;
            int y = p.second.second;
            store[x][y].insert(temp->val);
            if(temp->left!=NULL)
            {
                todo.push({temp->left, {x-1, y+1}});
            }
            if(temp->right!=NULL)
            {
                todo.push({temp->right, {x+1, y+1}});
            }
        } 
        vector<vector<int>> ans;
        for(auto i: store)
        {
            vector<int> cur;
            for(auto q : i.second)
            {
                cur.insert(cur.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(cur);
        }  
        return ans;
    }
};