//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284

/*----------------------RECURSION----------------*/
#include <iostream>
#include <vector>
using namespace std;
int helper(vector<int> value, int n, int maxWeight) 
{
	if(maxWeight==0)
	{
		return 0;
	}
	if(n==1)
	{
		return maxWeight*value[0];
	}
	int pick=-1e9;
	if(n<=maxWeight)
	{
		pick = value[n-1]+helper(value, n, maxWeight-n);
	}
	int not_pick = helper(value, n-1, maxWeight);
	return max(pick, not_pick);
}
int cutRod(vector<int> &price, int n)
{
	// n is rod length
	int ind = n;
	return helper(price, ind, n);
}


/*----------------------MEMOIZATION----------------*/
int helper(vector<int>& value, int n, int maxWeight, vector<vector<int>>& dp) {
    if (maxWeight==0 || n==0) {
        return 0;
    }
    if (dp[n][maxWeight] != -1) {
        return dp[n][maxWeight];
    }
    int pick = -1e9;
    if (n<= maxWeight) {
        pick = value[n-1] + helper(value, n, maxWeight-n, dp);
    }
    int not_pick = helper(value, n-1, maxWeight, dp);
    dp[n][maxWeight] = max(pick, not_pick);
    return dp[n][maxWeight];
}

int cutRod(vector<int>& price, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return helper(price, n, n, dp);
}