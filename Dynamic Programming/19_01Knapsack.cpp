//PROBLEM STATEMENT : https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542

/*----------------------RECURSION----------------*/
#include <iostream>
#include <vector>
using namespace std;
int helper(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	if(maxWeight<=0 || n<0)
	{
		return 0;
	}
	int pick=-1e9;
	if(weight[n]<=maxWeight)
	{
		pick = value[n]+helper(weight, value, n-1, maxWeight-weight[n]);
	}
	int not_pick = helper(weight, value, n-1, maxWeight);
	return max(pick, not_pick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	return helper(weight, value, n-1, maxWeight);
} 


/*----------------------MEMOIZATION----------------*/
int helper(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>>& dp) 
{
	if(maxWeight<=0 || n<0)
	{
		return 0;
	}
	if(dp[n][maxWeight]!=-1)
	{
		return dp[n][maxWeight];
	}
	int pick=-1e9;
	if(weight[n]<=maxWeight)
	{
		pick = value[n]+helper(weight, value, n-1, maxWeight-weight[n], dp);
	}
	int not_pick = helper(weight, value, n-1, maxWeight, dp);
	return dp[n][maxWeight] = max(pick, not_pick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return helper(weight, value, n-1, maxWeight, dp);
}


/*----------------------TABULATED----------------*/
int knapsack(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));
    for(int i = weight[0]; i<=maxWeight; i++)
	{
		dp[0][i] = value[0];
	}
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 0; j <= maxWeight; j++) 
		{
            int pick = -1e9;
            if (weight[i] <= j) {
                pick = value[i] + dp[i - 1][j - weight[i]];
            }
            int not_pick = dp[i - 1][j];
            dp[i][j] = max(pick, not_pick);
        }
    }
    return dp[n][maxWeight];
}


/*----------------------SPACE OPTIMIZED----------------*/
int knapsack(vector<int>& weight, vector<int>& value, int n, int maxWeight) {
    vector<int> dp(maxWeight + 1, 0);
    for(int i = weight[0]; i<=maxWeight; i++)
	{
		dp[i] = value[0];
	}
    for (int i = 1; i <n; i++) 
	{
		vector<int> temp(maxWeight+1, 0);
        for (int j = 0; j <= maxWeight; j++) 
		{
            int pick = 0;
            if (weight[i] <= j) {
                pick = value[i] + dp[j - weight[i]];
            }
            int not_pick = dp[j];
            temp[j] = max(pick, not_pick);
        }
		dp = temp;
    }
    return dp[maxWeight];
}