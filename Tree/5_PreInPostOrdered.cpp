//PreOrdered, postOredered, inOrdered at one place by using only one stack
//Time Complexity : O(3N)
//Space Complexity : o(3N)

#include <iostream>
#include <vector>
#include <stack>
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

vector<vector<int>> CommonDFS(TreeNode<int>* node)
{
    stack<pair<TreeNode<int>*, int>> s1;
    TreeNode<int>* temp = node;
    s1.push({temp, 1});
    vector<int> pre;
    vector<int> in;
    vector<int> post;
    while(!s1.empty())
    {
        auto it = s1.top();
        s1.pop();
        if(it.second==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            s1.push(it);
            if(it.first->left!=NULL)
            {
                s1.push({it.first->left, 1});
            }
        }
        else if(it.second==2)
        {
            in.push_back(it.first->data);
            it.second++;
            s1.push(it);
            if(it.first->right!=NULL)
            {
                s1.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    vector<vector<int>> ans;
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

int main() 
{
    TreeNode<int>* n1 = new TreeNode<int>(1);
    n1->left = new TreeNode<int>(2);
    n1->right = new TreeNode<int>(3);
    TreeNode<int>* n2 = n1->left;
    TreeNode<int>* n3 = n1->right;
    n2->left = new TreeNode<int>(4);
    n2->right = new TreeNode<int>(100);
    n3->left = new TreeNode<int>(99);
    n3->right = new TreeNode<int>(7);
    vector<vector<int>> ans = CommonDFS(n1);
    for(int i =0; i<ans.size(); i++)
    {
        for(int j = 0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}