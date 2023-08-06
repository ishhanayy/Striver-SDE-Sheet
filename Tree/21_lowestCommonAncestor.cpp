//Lowest Common Ancestor

#include <iostream>
using namespace std;

class TreeNode{
    public: 
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2)
{
    if(root==NULL || root==n1 || root==n2)
    {
        return root;
    }
    TreeNode* l1 = lowestCommonAncestor(root->left, n1, n2);
    TreeNode* l2 = lowestCommonAncestor(root->right, n1, n2);
    if(l1==NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }
    else
    {
        return root;
    }
}
int main()
{
    //cout<<"The Tree is : "<<endl;
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    TreeNode* l1 = root->left;
    TreeNode* r1 = root->right;
    TreeNode* l2 = l1->left = new TreeNode(40); //n1
    TreeNode* r2 = l1->right = new TreeNode(50);
    r2->left = new TreeNode(60);
    TreeNode* r3 = r2->right = new TreeNode(70); //n2
    int n1 = 40;
    int n2 = 70; // both are in the tree
    cout<<"We have to find the lowest common ancestor of the "<<n1<<" and "<<n2<<endl;
    cout<<"the lowest common ancestor would be : "<<lowestCommonAncestor(root, l2, r3)->data<<endl;
}