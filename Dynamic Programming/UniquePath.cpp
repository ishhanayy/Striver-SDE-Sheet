/*---------------------------RECURSION-------------------------------------------*/
#include <bits/stdc++.h> 
int helper(int m, int n)
{
	if(m==0 && n==0)
	{
		return 1;
	}
	if(m<0 || n<0)
	{
		return 0;
	}
	int a = helper(m-1, n);
	int b = helper(m, n-1);
	return a+b;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	return helper(m-1, n-1);
}


/*---------------------------MEMOIZATION-------------------------------------------*/
#include <bits/stdc++.h> 
int helper(int m, int n,vector<vector<int>>& dp)
{
	if(m==0 && n==0)
	{
		return 1;
	}
	if(m<0 || n<0)
	{
		return 0;
	}
	if(dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	int a = helper(m-1, n, dp);
	int b = helper(m, n-1, dp);
	return dp[m][n]=a+b;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return helper(m-1, n-1, dp);
}


/*---------------------------TABULATED-------------------------------------------*/
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else 
			{
                int a = 0;
                int b = 0;
                
                if (i > 0) {
                    a = dp[i-1][j];
                }
                
                if (j > 0) {
                    b = dp[i][j-1];
                }
                
                dp[i][j] = a+b;
            }
        }
        
    }
    
    return dp[m-1][n-1];
}


/*---------------------------MORE OPTIMIZED-------------------------------------------*/
int uniquePaths(int m, int n) {
    vector<int> dp(n, 0);
    
    for (int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                temp[j] = 1;
            } else {
                int a = 0;
                int b = 0;
                
                if (i > 0) {
                    a = dp[j];
                }
                
                if (j > 0) {
                    b = temp[j-1];
                }
                
                temp[j] = a + b;
            }
        }
        
        dp = temp;
    }
    
    return dp[n-1];
}
