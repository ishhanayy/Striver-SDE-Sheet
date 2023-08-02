/*In bottom view of BT: 
We do the following steps :
We know that we want the element which can be seen from the bottom of the tree.
That's why we will use the vertical view's line (which denotes the ertical position)
So accordingly we want the last element of the vertical line.
and for this we will use queue to store the node, it's line and the map which will store the line num, last element of that line.
And now watch the code, it is iterating till the q is not empty and while traversing it eventually checks for the left and the right child.
and whenever it pop any element, it just store the node in the temp and the vertical position in the line and then store the line and the node value in the map, and when any node reappears in the line then the map is updated with the latest node, which could make us nearer to the last node's value.
ANd after the traversal is completed, we will store the values of the node in the map into the vector and just returns it.*/

//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/bottom-view-of-binary-tree_893110?leftPanelTab=1

#include <bits/stdc++.h> 
#include <queue>
#include <map>
#include <vector>
/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
vector<int> bottomView(BinaryTreeNode<int> * root)
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }
    queue<pair<BinaryTreeNode<int>*, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while(!q.empty())
    {
        BinaryTreeNode<int>* temp = q.front().first;
        int line = q.front().second;
        q.pop(); 
        m[line] = temp->data;
        if (temp->left != NULL) {
            q.push({temp->left, line-1
        });
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
