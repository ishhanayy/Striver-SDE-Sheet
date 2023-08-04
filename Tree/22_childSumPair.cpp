#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

// defination of the tree node 
class TreeNode
{
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


/*What we are doing in child sum pair is that : 
1. Firstly we are checking if the sum of left and right child is less then the root , then the left->data = right->data = root->data.
2. If not then we are making the root->data = left->data+right->data*/

//converting the tree into child sum pair tree
void childSumPair(TreeNode* root)
{    
    if(root==NULL)
    {
        return;
    }
    int child = 0;
    if(root->left) //if the root's left child exist then only
    {
        child+=root->left->data;
    }
    if(root->right) //if the root's right child exist then only
    {
        child+=root->right->data;
    }
    if(child>=root->data) //if the root data is less then the root's left + root's right
    {
        root->data = child; //left + right = root
    }
    else
    {
        if(root->left) //if the root's left child exist then only
        {
            root->left->data = root->data;
        }
        else if(root->right) //if the root's right child exist then only
        {
            root->right->data = root->data;
        }
    }
    childSumPair(root->left);
    childSumPair(root->right);
    int after = 0;
    if(root->left){after+=root->left->data;}
    if(root->right){after+=root->right->data;}
    if(root->left || root->right) //if the root is not a leaf node, then only
    {
        root->data = after;
    }
}

//printing the tree
void print(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" "<<endl;
    print(root->left);
    print(root->right);
}

//taking the input for the tree
TreeNode* takeInput()
{
    cout<<"Enter the data of the root : ";
    int n; cin>>n;
    TreeNode* root = new TreeNode(n);
    //the number of the children would be less then or equal to 2;
    int num_child; cout<<"Enter the num of children of "<<n<<endl;
    cin>>num_child;
    if(num_child==1)
    {
        TreeNode* child = takeInput();
        root->left = child;
    }
    else if(num_child==2)
    {
        TreeNode* child = takeInput();
        root->left = child;
        TreeNode* child1 = takeInput();
        root->right = child1;
    }
    return root;
}


int main()
{
    TreeNode* root = takeInput();
    cout<<"We have to convert the tree into child sum pair "<<endl;
    cout<<"Before converting : "<<endl;
    print(root);
    childSumPair(root);
    cout<<"After Converting : "<<endl;
    print(root);
}


//PROBLEM STATEMENT: https://www.codingninjas.com/studio/problems/childrensumproperty_790723?leftPanelTab=1

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void helper(BinaryTreeNode < int > * root)
{
    if(root==NULL)
    {
        return;
    }
    int child = 0;
    if(root->left)
    {
        child+=root->left->data;
    }
    if(root->right)
    {
        child+=root->right->data;
    }
    if(child>=root->data)
    {
        root->data = child;
    }
    else
    {
        if(root->left)
        {
            root->left->data = root->data;
        }
        if(root->right)
        {
            root->right->data = root->data;
        }
    }
    helper(root->left);
    helper(root->right);
    int after = 0;
    if(root->left)
    {
        after+=root->left->data;
    }
    if(root->right)
    {
        after+=root->right->data;
    }
    if(root->left || root->right)
    {
        root->data = after;
    }
}
void changeTree(BinaryTreeNode < int > * root) 
{
    helper(root);
}