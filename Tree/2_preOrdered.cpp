//Depth Fisrt Search : It is the way to traverse the tree, but it goes deep and one of it's way is preorederd traversal where the order in which the deeper subtree considered is (Root, Right, Left).
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
void reccPreOrderedDFS(TreeNode<int>* node)  //(Root, left, right)
{
    if(node==NULL)
    {
        return;
    }
    cout<<node->data<<" ";
    reccPreOrderedDFS(node->left);
    reccPreOrderedDFS(node->right);
}


/*----------------------ITERATIVE APPROACH---------------------------*/
// void preOrderedDFS(TreeNode<int>* node)
// {
//     stack<TreeNode<int>*> s;
//     s.push(node);
//     while(!s.empty())
//     {
//         cout<<s.top()->data<<" ";
//         TreeNode<int>* temp = s.top();
//         s.pop();
//         if(temp->right!=NULL)
//         {
//             s.push(temp->right);
//         }
//         if(temp->left!=NULL)
//         {
//             s.push(temp->left);
//         }
//     }
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
    //preOrderedDFS(n1);
    reccPreOrderedDFS(n1);
    return 0;
}