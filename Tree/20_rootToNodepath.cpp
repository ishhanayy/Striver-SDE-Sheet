//PROBLEM STATEMENT : https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool helper(TreeNode* a, int b, vector<int>& ans)
{
    if(a==NULL)
    {
        return false;
    }
    ans.push_back(a->val);
    if(a->val==b)
    {
        return true;
    }
    bool l = helper(a->left, b, ans);
    bool r = helper(a->right, b, ans);
    if(l == true || r == true)
    {
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* a, int b) 
{
    vector<int> ans;
    if(a==NULL)
    {
        return ans;
    }
    bool temp = helper(a, b, ans);
    return ans;
}