// PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?leftPanelTab=0

/*--------------------------------------RECURSION------------------------------------------------*/
#include <bits/stdc++.h> 
int helper(vector<vector<int>>& grid, int m, int n)
    {
        if(m==0 && n==0)
        {
            return grid[m][n];
        }
        if(m<0 || n<0)
        {
            return 1e9;
        }
        int a = grid[m][n] + helper(grid, m-1, n);
        int b = grid[m][n] + helper(grid, m, n-1);
        return min(a,b);
    }
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size(); // size of the row
    int n = (grid[0]).size(); // size of the coloumn
    return helper(grid, m-1, n-1);
}


/*--------------------------------------MEMOIZATION------------------------------------------------*/
#include <bits/stdc++.h> 
int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int m, int n)
    {
        if(m==0 && n==0)
        {
            return grid[m][n];
        }
        if(m<0 || n<0)
        {
            return 1e9;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int a = grid[m][n] + helper(grid, dp, m-1, n);
        int b = grid[m][n] + helper(grid, dp, m, n-1);
        return dp[m][n] = min(a,b);
    }
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size(); // size of the row
    int n = (grid[0]).size(); // size of the coloumn
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(grid, dp, m-1, n-1);
}


/*--------------------------------------TABULATED------------------------------------------------*/
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size(); // size of the row
    int n = (grid[0]).size(); // size of the coloumn
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for(int i = 0; i<m; i++)
    {
        for(int j =0; j<n; j++)
        {
            if(i==0 && j==0)
            {
                dp[0][0] = grid[0][0];
            }
            else
            {
                int a = 1e9;
                int b =1e9;
                if(i>0)
                {
                    a = grid[i][j]+dp[i-1][j];
                }
                if(j>0)
                {
                    b = grid[i][j]+dp[i][j-1];
                }
                dp[i][j] = min(a,b);
            }
        }
    }
    return dp[m-1][n-1];
}