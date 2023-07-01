//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471

/*----------------------RECURSION----------------*/
#include <iostream>
#include <vector>
long helper(int *arr, int n, int value)
{
    if(n==0)
    {
        if(value%arr[0]==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    long take = 0;
    if (value>=arr[n])
    {
        take = helper(arr, n, value - arr[n]);
    }
    long not_take = helper(arr, n-1, value);
    return take+not_take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    return helper(denominations, n-1, value);
}


/*----------------------MEMOIZATION----------------*/
long helper(int *arr, int n, int value, vector<vector<long>>& dp)
{
    if(n==0)
    {
        if(value%arr[0]==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[n][value]!=-1)
    {
        return dp[n][value];
    }

    long take = 0;
    if (value>=arr[n])
    {
        take = helper(arr, n, value - arr[n], dp);
    }
    long not_take = helper(arr, n-1, value, dp);
    return dp[n][value] = take+not_take;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    return helper(denominations, n-1, value, dp);
}
