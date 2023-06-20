//PROBLEM STATEMENT : https://www.codingninjas.com/codestudio/problems/triangle_1229398?leftPanelTab=1

/*------------------RECURSION-------------------------------*/
#include <bits/stdc++.h> 
int helper(vector<vector<int>>& triangle, int i, int m, int n)
{
	//The reson why the recursion will start from 0 is that it is the fixed point as the starting point is fixed and as we have to reach at last row's  element and it is not fixed.
	if(m==i)
	{
		return triangle[m][n];
	}
	int a = triangle[m][n]+helper(triangle, i, m+1, n);
	int b = triangle[m][n]+helper(triangle, i, m+1, n+1);
	return min(a,b);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	//n is the num of elements present in the last row of the triangle 
	return helper(triangle, n-1, 0, 0); //0 is the coloumn num annd row num of starting
}


/*--------------------MEMOIZATION---------------------------*/
#include <bits/stdc++.h> 
int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int m, int n)
{
	if(m==i)
	{
		return triangle[m][n];
	}
	if(dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	int a = triangle[m][n]+helper(triangle, dp, i, m+1, n);
	int b = triangle[m][n]+helper(triangle, dp, i, m+1, n+1);
	return dp[m][n] =  min(a,b);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return helper(triangle, dp, n-1, 0, 0); 
}


/*--------------------TABULATED---------------------------*/
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n));
	for(int i = 0; i<n ; i++)
	{
		dp[n-1][i] = triangle[n-1][i];
	}
	for(int i = n-2; i>=0; i--)
	{
		for(int j = i; j>=0;j--)
		{
			int a = triangle[i][j]+dp[i+1][j];
			int b = triangle[i][j]+dp[i+1][j+1];
			dp[i][j] = min(a, b);
		}
	}
	return dp[0][0];
}


/*--------------------SPACE OPTIMIZED---------------------------*/
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<int> dp(n);
	for(int i = 0; i<n ; i++)
	{
		dp[i] = triangle[n-1][i];
	}
	for(int i = n-2; i>=0; i--)
	{
		vector<int> temp(i+1);
		for(int j = i; j>=0;j--)
		{
			int a = triangle[i][j]+dp[j];
			int b = triangle[i][j]+dp[j+1];
			temp[j] = min(a, b);
		}
		dp = temp;
	}
	return dp[0];
	
}