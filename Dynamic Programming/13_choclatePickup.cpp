//PROBLEM STATEMENT : https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?leftPanelTab=0

/*-------------------------RECURSION----------------*/
#include <bits/stdc++.h> 
int helper(int r, int c, vector<vector<int>>& grid, int j1, int i, int j2)
{
    if(j1<0||j1>=c||j2<0||j2>=c)
    {
        return -1e9;
    }
    if(i==r-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        else{return (grid[i][j1]+grid[i][j2]      );}
    }
    vector<int> dp{-1, 0, 1};
    int final_max = -1e9;
    for(int k = 0; k<dp.size(); k++)
    {
        for(int j =0; j<dp.size(); j++)
        {
            int a = 0;
            if(j1==j2)
            {
                a = grid[i][j1];
            }
            else
            {
                a = grid[i][j1]+grid[i][j2];
            }
            a+=helper(r, c, grid, j1+dp[k], i+1, j2+dp[j]);
            final_max = max(final_max, a);
        }
    }
    return final_max;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    int alice = 0; // the position of alice in the first row
    int i = 0; // the initial row of grid
    int bob = c-1; // the position of bob in the first row
    return helper(r, c, grid, alice, i, bob);
}


/*----------------------MEMOIZATION----------------*/
#include <bits/stdc++.h> 
int helper(int r, int c, vector<vector<int>>& grid, int j1, int i, int j2, vector<vector<vector<int>>> &dp1)
{
    if(j1<0||j1>=c||j2<0||j2>=c)
    {
        return -1e9;
    }
    if(i==r-1)
    {
        if(j1==j2)
        {
            return grid[i][j1];
        }
        else{return (grid[i][j1]+grid[i][j2]);}
    }
    if(dp1[i][j1][j2]!=-1)
    {
        return dp1[i][j1][j2];
    }
    vector<int> dp{-1, 0, 1};
    int final_max = -1e9;
    for(int k = 0; k<dp.size(); k++)
    {
        for(int j =0; j<dp.size(); j++)
        {
            int a = 0;
            if(j1==j2)
            {
                a = grid[i][j1];
            }
            else
            {
                a = grid[i][j1]+grid[i][j2];
            }
            a+=helper(r, c, grid, j1+dp[k], i+1, j2+dp[j], dp1);
            final_max = max(final_max, a);
        }
    }
    return dp1[i][j1][j2] = final_max;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int alice = 0; 
    int i = 0; 
    int bob = c-1; 
    vector<vector<vector<int>>> dp1(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return helper(r, c, grid, alice, i, bob, dp1);
}


/*-------------------------TABULATION----------------*/
int maximumChocolates(int n, int c, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp1(n, vector<vector<int>>(c, vector<int>(c)));

    for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            if (j1 == j2) {
                dp1[n-1][j1][j2] = grid[n-1][j1];
            } else {
                dp1[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    for (int i = n-2; i >= 0; i--) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                vector<int> dp{-1, 0, 1};
                int final_max = -1e9;

                for (int k = 0; k <dp.size(); k++) {
                    for (int j = 0; j<dp.size(); j++) {
                        int a = 0;
                        if (j1 == j2) {
                            a = grid[i][j1];
                        } else {
                            a = grid[i][j1] + grid[i][j2];
                        }
                        if(j1+dp[k]>= 0 && j1+dp[k]<c && j2+dp[j]>=0 && j2+dp[j]<c) {
                            a += dp1[i+1][j1+dp[k]][j2+dp[j]];
                        } else {
                            a = -1e9;
                        }
                        final_max = max(final_max, a);
                    }
                }
                dp1[i][j1][j2] = final_max;
            }
        }
    }
    return dp1[0][0][c-1];
}
