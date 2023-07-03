//Depth Fisrt Search : It is the way to traverse the tree, but it goes deep and one of it's way is inorederd traversal where the order in which the deeper subtree considered is (Left, root, Right).
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


/*----------------------RECCURSIVE APPROACH---------------------------*/
void reccInOrderedDFS(TreeNode<int>* node)  //(Root, left, right)
{
    if(node==NULL)
    {
        return;
    }
    reccInOrderedDFS(node->left);
    cout<<node->data<<" ";
    reccInOrderedDFS(node->right);
}


/*----------------------ITERATIVE APPROACH---------------------------*/
// vector<int> InOrderedDFS(TreeNode<int>* node)
// {
//     vector<int> ans;
//     TreeNode<int>* temp = node;
//     stack<TreeNode<int>*> s;
//     while(true)
//     {
//         if(temp!=NULL)
//         {
//             s.push(temp);
//             temp = temp->left;
//         }
//         else
//         {
//             if(s.empty())
//             {
//                 break;
//             }
//             temp = s.top();
//             ans.push_back(temp->data);
//             s.pop();
//             temp = temp->right;
//         }
//     }
//     return ans;
// }

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
    // vector<int> ans = InOrderedDFS(n1);
    // for(int i =0; i<ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    reccInOrderedDFS(n1);
    cout<<endl;
    return 0;
}