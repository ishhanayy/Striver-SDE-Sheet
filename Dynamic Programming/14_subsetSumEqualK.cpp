//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

/*-------------------------RECURSION----------------*/
#include <bits/stdc++.h>
bool helper(int n, int k, vector<int>& arr)
{
    if(k==0)
    {
        return true;
    }
    if(n==0)
    {
        return arr[n]==k;
    }
    bool take = false;
    if(k>=arr[n])
    {
        take = helper(n-1, k-arr[n], arr);
    }
    bool not_take = helper(n-1, k, arr);
    return take||not_take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    // Write your code here.
    return helper(n, k, arr);
}


/*----------------------MEMOIZATION----------------*/
#include <bits/stdc++.h>
bool helper(int n, int k, vector<int>& arr, vector<vector<bool>>& dp)
{
    if(k==0)
    {
        return true;
    }
    if(n==0)
    {
        return arr[n]==k;
    }
    if(dp[n][k]!=0)
    {
        return dp[n][k];
    }
    bool take = false;
    if(k>=arr[n])
    {
        take = helper(n-1, k-arr[n], arr, dp);
    }
    bool not_take = helper(n-1, k, arr, dp);
    return dp[n][k]=take||not_take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
    return helper(n, k, arr, dp);
}


/*-------------------------TABULATION----------------*/
bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));

    for(int i = 0; i<=n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0]<=k)
        dp[0][arr[0]] = true;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            bool take = false;
            if (j >= arr[i])
            {
                take = dp[i-1][j-arr[i]];
            }
            bool not_take = dp[i-1][j];
            dp[i][j] = take || not_take;
        }
    }

    return dp[n][k];
}