//PROBLEM STATEMENT : https://leetcode.com/problems/combination-sum/

/*------------------------------RECCURSION---------------------------------------*/
class Solution {
public:
    void helper(vector<int> arr, int n, int i, vector<vector<int>>& ans, vector<int>& curr, int target)
    {
        if(i==n)
        {
            if(target==0)
            {
                ans.push_back(curr);
            }
            return;
        }
        if(arr[i]<=target)
        {
            curr.push_back(arr[i]);
            helper(arr, n, i, ans, curr, target-arr[i]);
            curr.pop_back();
        }
        helper(arr, n, i+1, ans, curr, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> curr;
        int n = candidates.size();    
        int i =0;
        helper(candidates, n, i, ans, curr, target);
        return ans;
    }
};