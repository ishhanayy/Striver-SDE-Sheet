//PROBLEM STATEMENT: https://www.codingninjas.com/studio/problem-details/target-sum_4127362

/*----------------------RECURSION----------------*/
#include <iostream>
#include <vector>
using namespace std;
int helper(vector<int>& num, int n, int tar)
{
    if (n == 0) 
    {
      if (tar == 0 && num[0] == 0) 
      {
        return 2;
      } 
      else if (num[0] == tar||tar == 0) 
      {
        return 1;
      } 
      else
      {
        return 0;
        }
    }
    int pick = 0;
    if(tar>=num[n])
    {
        pick = helper(num, n-1, tar-num[n]);
    }
    int not_pick = helper(num, n-1, tar);
    return pick+not_pick;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    return helper(num, n-1, tar);
}
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto it:arr)
    {
        sum+=it;
    }
    if((sum-d)<0 || (sum-d)%2!=0)
    {
        return false;
    }
    return findWays(arr,(sum-d)/2);
}
int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}



/*----------------------MEMOIZATION----------------*/
int helper(vector<int>& num, int n, int tar, vector<vector<int>>& dp) {
    if (n == 0) 
    {
      if (tar == 0 && num[0] == 0) 
      {
        return 2;
      } 
      else if (num[0] == tar||tar == 0) 
      {
        return 1;
      } 
      else
      {
        return 0;
        }
      
    }
    if (dp[n][tar] != -1) {
        return dp[n][tar];
    }
    int pick = 0;
    if (tar >= num[n]) {
        pick = helper(num, n - 1, tar - num[n], dp);
    }
    int not_pick = helper(num, n - 1, tar, dp);
    return dp[n][tar] = (pick + not_pick);
}

int findWays(vector<int>& num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return helper(num, n - 1, tar, dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(auto it:arr)
    {
        sum+=it;
    }
    if((sum-d)<0 || (sum-d)%2!=0)
    {
        return false;
    }
    return findWays(arr,(sum-d)/2);
}