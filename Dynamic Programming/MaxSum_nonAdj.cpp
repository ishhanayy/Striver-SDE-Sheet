/*---------------RECURSION--------------------------*/
#include <bits/stdc++.h> 

int helper(vector<int>& nums, int n)
{
    if(n == 0)
    {
        return nums[0];
    }
    if(n<0)
    {
        return 0;
    }
    int pick = nums[n]+helper(nums, n-2); // n-2 so that we can avoid adjacent element
    int not_pick = 0+helper(nums, n-1);
    return max(pick, not_pick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    return helper(nums, n-1);
}


/*--------------------MEMOIZAITON---------------------*/
#include <bits/stdc++.h> 
int helper(vector<int>& nums,vector<int>& dp, int n)
{
    if(n == 0)
    {
        return nums[0];
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int pick = nums[n]+helper(nums, dp, n-2); // n-2 so that we can avoid adjacent element
    int not_pick = 0+helper(nums, dp, n-1);
    return dp[n] = max(pick, not_pick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    return helper(nums, dp, n-1);
}

/*----------------TABULATED-----------------------*/
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    if (n == 0) {
        return 0;
    } 
    else if (n == 1) {
        return nums[0];
    } 
    else if (n == 2) {
        return max(nums[0], nums[1]);
    }
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i<n; i++)
    {
        int pick = nums[i]+dp[i-2];
        int not_pick = dp[i-1];
        dp[i] = max(pick, not_pick);
    }
    return dp[n-1];
}