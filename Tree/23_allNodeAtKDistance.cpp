// // Print all of the nodes at distance k(in upward, downwards) from a given node

// #include <iostream>
// #include <map>
// #include <vector>
// #include <queue>
// using namespace std;

// // defination of the tree node
// class TreeNode
// {
// public:
//     int data;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//     }
// };

// // printing the tree
// void print(TreeNode *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     cout << root->data << " ";
//     print(root->left);
//     print(root->right);
// }

// // taking the input for the tree
// TreeNode *takeInput()
// {
//     cout << "Enter the data of the root : ";
//     int n;
//     cin >> n;
//     TreeNode *root = new TreeNode(n);
//     // the number of the children would be less then or equal to 2;
//     int num_child;
//     cout << "Enter the num of children of " << n << endl;
//     cin >> num_child;
//     if (num_child == 1)
//     {
//         TreeNode *child = takeInput();
//         root->left = child;
//     }
//     else if (num_child == 2)
//     {
//         TreeNode *child = takeInput();
//         root->left = child;
//         TreeNode *child1 = takeInput();
//         root->right = child1;
//     }
//     return root;
// }

// void ParentTrack(TreeNode *root, map<TreeNode*, TreeNode *> &parent_track)
// {
//     // if (root == NULL)
//     // {
//     //     return;
//     // }
//     // if (root->left)
//     // {
//     //     parent_track[root->left] = root;
//     //     ParentTrack(root->left, parent_track);
//     // }
//     // if (root->right)
//     // {
//     //     parent_track[root->right] = root;
//     //     ParentTrack(root->right, parent_track);
//     // }
//     queue<TreeNode*> q;
//     q.push(root);
//     while(!q.empty())
//     {
//         TreeNode* temp = q.front();
//         q.pop();
//         cout<<"b"<<endl;
//         if(temp->left)
//         {
//             parent_track[temp->left] = temp;
//             q.push(temp->left);
//         }
//         if(temp->right)
//         {
//             parent_track[temp->right] = temp;
//             q.push(temp->right);
//         }
//     }
// }

// vector<int> NodesAtDistanceK(TreeNode *root, TreeNode *node, int k)
// {
//     map<TreeNode *, TreeNode *> parent_trake; //[child]->parent (child ka parent)
//     ParentTrack(root, parent_trake);
//     map<TreeNode *, bool> visited;
//     queue<TreeNode *> q;
//     q.push(node);
//     visited[node] = true;
//     int length = 0;
//     while (!q.empty())
//     {
//         length+=1;
//         if (length == k)
//         {
//             break;
//         }
//         int size = q.size();
//         for (int i = 0; i < size; i++)
//         {
//             TreeNode *temp = q.front();
//             q.pop();
//             if (temp->left && !visited[temp->left])
//             {
//                 q.push(temp->left);
//                 visited[temp->left] = true;
//             }
//             if (temp->right && !visited[temp->right])
//             {
//                 q.push(temp->right);
//                 visited[temp->right] = true;
//             }
//             if (parent_trake[temp] && !visited[parent_trake[temp]])
//             {
//                 q.push(parent_trake[temp]);
//                 visited[parent_trake[temp]] = true;
//             }
//         }
//     }
//     vector<int> ans;
//     bool hint = q.empty();
//     cout<<hint<<endl;
//     while (!q.empty())
//     {
//         cout<<"a"<<endl;
//         ans.push_back(q.front()->data);
//         q.pop();
//     }
//     return ans;
// }

// int main()
// {
//     TreeNode *root = takeInput();
//     cout << "The tree looks like : ";
//     print(root);
//     cout << endl;
//     cout << "We have to find the nodes which are at the distance k from the given node " << endl;
//     cout << "Enter the node for which you want to find the nodes at distance k" << endl;
//     int n;
//     cin >> n;
//     TreeNode *node = new TreeNode(n);
//     cout << "Enter the distance at which you to find the nodes : " << endl;
//     int k;
//     cin >> k;
//     vector<int> ans = NodesAtDistanceK(root, node, k);
//     for(int i =0; i<ans.size(); i++)
//     {
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
// }
//Upcode of vs code



//PROBLEM STATEMENT : https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void ParentTrack(TreeNode* root, map<TreeNode*, TreeNode*>& m)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left)
            {
                m[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                m[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
    }
    vector<int> helper(TreeNode* root, TreeNode* target, int k)
    {
        map<TreeNode*, TreeNode*> parent_track;
        ParentTrack(root, parent_track);
        queue<TreeNode*> q;
        map<TreeNode*, bool> visited;
        int length = 0;
        q.push(target);
        visited[target] = true;
        while(!q.empty())
        {
            int size = q.size();
            if(length++==k)
            {
                break;
            }
            for(int i =0; i<size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if(parent_track[temp] && !visited[parent_track[temp]])
                {
                    q.push(parent_track[temp]);
                    visited[parent_track[temp]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        return helper(root, target, k);
    }
};