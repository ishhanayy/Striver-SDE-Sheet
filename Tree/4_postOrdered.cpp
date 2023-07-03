//Depth Fisrt Search : It is the way to traverse the tree, but it goes deep and one of it's way is postorederd traversal where the order in which the deeper subtree considered is (Left, Right, root).


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
void reccPostOrderedDFS(TreeNode<int>* node)  //(Root, left, right)
{
    if(node==NULL)
    {
        return;
    }
    reccPostOrderedDFS(node->left);
    reccPostOrderedDFS(node->right);
    cout<<node->data<<" ";
}


/*----------------------ITERATIVE APPROACH---------------------------*/

/*-------------------USING 2 STACK-----------------------*/
// vector<int> postOrderedDFS(TreeNode<int>* node)
// {
//     vector<int> ans;
//     if(node==NULL)
//     {
//         return ans;
//     }
//     stack<TreeNode<int>*> s1;
//     stack<TreeNode<int>*> s2;
//     TreeNode<int>* temp = node;
//     s1.push(temp);
//     while(!s1.empty())
//     {
//         temp = s1.top();
//         s1.pop();
//         s2.push(temp);
//         if(temp->left!=NULL)
//         {
//             s1.push(temp->left);
//         }
//         if(temp->right!=NULL)
//         {
//             s1.push(temp->right);
//         }
//     }
//     while(!s2.empty())
//     {
//         ans.push_back(s2.top()->data);
//         s2.pop();
//     }
//     return ans;
// }

/*-------------------USING 1 STACK-----------------------*/
// vector<int> postOrderedDFS(TreeNode<int>* node)
// {
//     vector<int> ans;
//     if(node==NULL)
//     {
//         return ans;
//     }
//     stack<TreeNode<int>*> s1;
//     //stack<TreeNode<int>*> s2;
//     TreeNode<int>* temp = node;
//     s1.push(temp);
//     while(!s1.empty())
//     {
//         temp = s1.top();
//         s1.pop();
//         ans.push_back(temp->data);
//         if(temp->left!=NULL)
//         {
//             s1.push(temp->left);
//         }
//         if(temp->right!=NULL)
//         {
//             s1.push(temp->right);
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
    // vector<int> ans = postOrderedDFS(n1);
    // for(int i = ans.size()-1; i>=0; i--)
    // {
    //     cout<<ans[i]<<" ";
    // }
    reccPostOrderedDFS(n1);
    cout<<endl;
    return 0;
}