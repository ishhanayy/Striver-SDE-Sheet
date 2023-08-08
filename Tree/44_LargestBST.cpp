//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/largest-bst-subtree_893103

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

#include <climits> // Include this for INT_MAX and INT_MIN

class NodeVal {
public:
    int minNode;
    int maxNode;
    int maxSize;
    
    NodeVal(int mini, int maxi, int size) {
        minNode = mini;
        maxNode = maxi;
        maxSize = size;
    }
};

NodeVal helper(TreeNode* root) {
    if (!root) {
        return NodeVal(INT_MAX, INT_MIN, 0); // Missing semicolon here
    }
    
    auto leftIterator = helper(root->left);
    auto rightIterator = helper(root->right);
    
    if (leftIterator.maxNode < root->data && root->data < rightIterator.minNode) {
        // it is iterator
        return NodeVal(min(root->data, leftIterator.minNode), max(root->data, rightIterator.maxNode), 1 + leftIterator.maxSize + rightIterator.maxSize); // Fixed maxSize typo
    }
    
    return NodeVal(INT_MIN, INT_MAX, max(leftIterator.maxSize, rightIterator.maxSize)); // Fixed typo in max function
}

int largestBST(TreeNode* root) {
    return helper(root).maxSize;
}
