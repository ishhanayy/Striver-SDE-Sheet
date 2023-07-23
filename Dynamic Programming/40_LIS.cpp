//PROBLEM STATEMENT : https://leetcode.com/problems/longest-increasing-subsequence/

/*----------------------RECURSION----------------*/
class Solution {
public:
    int helper(vector<int>& nums, int prev_ind, int ind)
    {
        if(ind==nums.size())
        {
            return 0;
        }
        int take = 0;
        if(prev_ind == -1 || nums[ind]>nums[prev_ind])
        {
            take = 1+helper(nums, ind, ind+1);
        }
        int not_take = 0+helper(nums, prev_ind, ind+1);
        return max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int prev_ind = -1;
        int ind = 0;
        return helper(nums, prev_ind, ind);    
    }
};


/*----------------------MEMOIZATION----------------*/
class Solution {
public:
    int helper(vector<int>& nums, int prev_ind, int ind, vector<vector<int>>& dp)
    {
        if(ind==nums.size())
        {
            return 0;
        }
        if(dp[ind][prev_ind+1]!=-1)
        {
            return dp[ind][prev_ind+1];
        }
        int take = 0;
        if(prev_ind == -1 || nums[ind]>nums[prev_ind])
        {
            take = 1+helper(nums, ind, ind+1, dp);
        }
        int not_take = 0+helper(nums, prev_ind, ind+1, dp);
        return dp[ind][prev_ind+1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int prev_ind = -1;
        int ind = 0;
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return helper(nums, prev_ind, ind, dp);    
    }
};


/*----------------------TABULATION----------------*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));
        //return helper(nums, prev_ind, ind, dp);   
        for(int ind =nums.size()-1; ind>=0; ind--)
        {
            for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--)
            {
                int take = 0;
                if(prev_ind == -1 || nums[ind]>nums[prev_ind])
                {
                    take = 1+dp[ind+1][ind+1];
                }
                int not_take = 0+dp[ind+1][prev_ind+1];
                dp[ind][prev_ind+1] = max(take, not_take);
            }
        }
        return dp[0][-1+1];
    }
};