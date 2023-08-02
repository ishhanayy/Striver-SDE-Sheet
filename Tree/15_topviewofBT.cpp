//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/top-view-of-the-binary-tree_893067?leftPanelTab=2

#include <queue>
#include <map>

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL) {
      return ans;
    }
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    map<int, int> m; //it will store the line and the node value;
    while(!q.empty())
    {
        auto i =  q.front();
        q.pop();
        TreeNode<int>* temp = i.first; //it will be the node;
        int line = i.second;
        if (m.find(line) == m.end()) //here we are checking if the line already exist or not, if not then only we will insert the value in it, otherwise not inserting  
        {
            m[line] = temp->val;
        }
        if(temp->left!=NULL)
        {
            q.push({temp->left, line-1});
        } 
        if(temp->right!=NULL)
        {
            q.push({temp->right, line+1});
        }
    }
    for(auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}