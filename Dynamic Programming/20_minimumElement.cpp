//PROBLEM STATEMENT : https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

/*----------------------RECURSION----------------*/
#include <iostream>
#include <vector>
using namespace std;
int helper(vector<int> &nums, int x, int n){
    if(n==0){
      if (x % nums[0] == 0) {
        return x / nums[0];
      } else {
        return 1e9;
      }
    }
    int pick = 1e9;
    if (nums[n] <= x) {
      pick = 1 + helper(nums, x - nums[n], n);
    }
    int not_pick = helper(nums, x, n-1);
    return min(pick,not_pick);
}
int minimumElements(std::vector<int>& nums, int x)
{
    int n = nums.size() - 1;
    int ans = helper(nums, x, n);
    if (ans >= 1e9)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}


/*----------------------MEMOIZATION----------------*/
int helper(vector<int> &nums, int x, int n, vector<vector<int>>& dp){
    if(n==0){
      if (x % nums[0] == 0) {
        return x / nums[0];
      } else {
        return 1e9;
      }
    }
    if(dp[n][x]!=-1)
    {
      return dp[n][x];
    }
    int pick = 1e9;
    if (nums[n] <= x) {
      pick = 1 + helper(nums, x - nums[n], n, dp);
    }
    int not_pick = helper(nums, x, n-1, dp);
    return dp[n][x] = min(pick,not_pick);
}
int minimumElements(std::vector<int>& nums, int x)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    int ans = helper(nums, x, n-1, dp);
    if (ans >= 1e9)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

