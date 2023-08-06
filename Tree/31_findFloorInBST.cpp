//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/floor-from-bst_920457?leftPanelTab=1

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
//Floor = The floor is the value of the BST which is lesser than or equal to the x and we have to maximize the floor value which can be feasible

int floorInBST(TreeNode<int> * root, int x)
{
    int floor = -1;
    TreeNode<int>* temp = root;
    while(temp!=NULL)
    {
        if(temp->val==x)
        {
            floor = temp->val;
            break;
        }
        else if(temp->val>x)
        {
            temp = temp->left;
        }
        else
        {
            floor = temp->val;
            temp = temp->right;
        }
    }
    return floor;
}