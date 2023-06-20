//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998?leftPanelTab=1

/*-------------------------RECURSION----------------*/
#include <bits/stdc++.h> 
int helper(vector<vector<int>>& matrix,int m, int j, int n)
{
    if(j<0 || j>=n)
    {
        return -1e9;
    }
    if(m==0)
    {
        return matrix[m][j];
    }
    int a = matrix[m][j]+helper(matrix, m-1, j-1, n); // Daigonally left
    int c = matrix[m][j]+helper(matrix, m-1, j+1, n); // Daogonally right
    int b = matrix[m][j]+helper(matrix, m-1, j, n);   // just above
    return max(a, max( b, c));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = (matrix[0]).size();
    int finalmax = -1e9;
    for(int i = 0; i<n; i++)
    {
        finalmax = max(finalmax, helper(matrix, m-1, i,  n));
    }
    return finalmax;
}


/*-------------------------MEMOIZATION----------------*/
#include <bits/stdc++.h> 
int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int m, int j, int n)
{
    if(j<0 || j>=n)
    {
        return -1e9;
    }
    if(m==0)
    {
        return matrix[m][j];
    }
    if(dp[m][j]!=-1)
    {
        return dp[m][j];
    }
    int a = matrix[m][j]+helper(matrix, dp, m-1, j-1, n); // Daigonally left
    int c = matrix[m][j]+helper(matrix, dp, m-1, j+1, n); // Daogonally right
    int b = matrix[m][j]+helper(matrix, dp, m-1, j, n);   // just above
    return dp[m][j] = max(a, max( b, c));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = (matrix[0]).size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int finalmax = -1e9;
    for(int i = 0; i<n; i++)
    {
        finalmax = max(finalmax, helper(matrix, dp, m-1, i,  n));
    }
    return finalmax;
}


/*-------------------------TABULATION----------------*/
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = (matrix[0]).size();
    vector<vector<int>> dp(m, vector<int>(n));
    for(int i =0; i<n; i++)
    {
        dp[0][i] = matrix[0][i];
    }
    for(int i = 1; i<m; i++)
    {
        for(int j = 0; j<n ; j++)
        {
            int a = -1e9;
            int c = -1e9;
            if(j>0)
            {
                a = matrix[i][j]+dp[i-1][j-1];
            }
            int b = matrix[i][j]+dp[i-1][j];
            if(j<n-1)
            {
                c = matrix[i][j]+dp[i-1][j+1];
            }
            dp[i][j] = max(a, max( b, c));
        }
    }
    int finalmax = -1e9;
    for(int i =0; i<n; i++)
    {
        finalmax=max(finalmax, dp[m-1][i]);
    }
    return finalmax;
}


/*-------------------------SPACE OPTIMIZED----------------*/
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = (matrix[0]).size();
    vector<int> dp(n);
    for(int i =0; i<n; i++)
    {
        dp[i] = matrix[0][i];
    }
    for(int i = 1; i<m; i++)
    {
        vector<int> temp(n);
        for(int j = 0; j<n ; j++)
        {
            int a = -1e9;
            int c = -1e9;
            if(j>0)
            {
                a = matrix[i][j]+dp[j-1];
            }
            int b = matrix[i][j]+dp[j];
            if(j<n-1)
            {
                c = matrix[i][j]+dp[j+1];
            }
            temp[j] = max(a, max( b, c));
        }
        dp = temp;
    }
    int finalmax = -1e9;
    for(int i =0; i<n; i++)
    {
        finalmax=max(finalmax, dp[i]);
    }
    return finalmax;
}