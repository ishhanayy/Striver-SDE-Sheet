//PROBLEM STATEMENT : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class bstIterator {
    stack<TreeNode*> s;
    bool reverse;
    
public:
    bstIterator(TreeNode* root, bool r) {
        reverse = r;
        pushall(root);
    }
    
    void pushall(TreeNode* root) {
        while (root) {
            s.push(root);
            if (!reverse) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushall(reverse ? temp->left : temp->right);
        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        bstIterator l(root, false);  // next
        bstIterator r(root, true);   // before
        int i = l.next();
        int j = r.next();
        
        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = l.next();
            } else {
                j = r.next();
            }
        }
        return false;
    }
};
