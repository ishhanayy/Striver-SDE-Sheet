//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/ceil-from-bst_920464?leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ceil = -1;
    BinaryTreeNode<int>* temp = node;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            ceil = temp->data;
            break;
        }
        else if(temp->data>x)
        {
            ceil = temp->data;
            temp = temp->left;
        }
        else 
        {
            //temp->data<key(x)
            temp = temp->right;
        }
    }
    return ceil;
}