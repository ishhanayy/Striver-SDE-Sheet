//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029

/*----------------------RECURSION----------------*/
#include <iostream>
#include <vector>
using namespace std;
int helper(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	if(n==0)
	{
		return ((int)(maxWeight/weight[0]))*value[0];
	}
	int pick=-1e9;
	if(weight[n]<=maxWeight)
	{
		pick = value[n]+helper(weight, value, n, maxWeight-weight[n]);
	}
	int not_pick = helper(weight, value, n-1, maxWeight);
	return max(pick, not_pick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return helper(weight, profit, n-1, w);
}


/*----------------------MEMOIZATION----------------*/
int helper(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>>& dp) 
{
	if(n==0)
	{
		return ((int)(maxWeight/weight[0]))*value[0];
	}
    if(dp[n][maxWeight]!=-1)
    {
        return dp[n][maxWeight];
    }
	int pick=-1e9;
	if(weight[n]<=maxWeight)
	{
		pick = value[n]+helper(weight, value, n, maxWeight-weight[n], dp);
	}
	int not_pick = helper(weight, value, n-1, maxWeight, dp);
	return dp[n][maxWeight] = max(pick, not_pick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return helper(weight, profit, n-1, w, dp);
}


/*----------------------TABULATION----------------*/
int unboundedKnapsack(int n, int maxWeight, vector<int> &value, vector<int> &weight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for(int i = 0; i<=maxWeight; i++)
	{
		dp[0][i] = ((int)(i/weight[0]))*value[0];
	}
    for (int i = 1; i <n; i++) 
	{
        for (int j = 0; j <= maxWeight; j++) 
		{
            int pick = 0;
            if (weight[i] <= j) {
                pick = value[i] + dp[i][j - weight[i]];
            }
            int not_pick = dp[i - 1][j];
            dp[i][j] = max(pick, not_pick);
        }
    }
    return dp[n-1][maxWeight];
}