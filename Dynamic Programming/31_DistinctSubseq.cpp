//PROBLEM STATMENT : https://leetcode.com/problems/distinct-subsequences/

/*------------------------RECURSION------------------------*/
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    int helper(string s, string t, int i, int j)
    {
        if(j<0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }
        if(s[i]==t[j])
        {
            return helper(s,t, i-1, j-1) + helper(s, t, i-1, j);
        }
        return helper(s, t, i-1, j);
    }
    int numDistinct(string s, string t) 
    {
        int i = s.size()-1;
        int j = t.size()-1;
        return helper(s, t, i, j);    
    }
};


/*---------------------------MEMOIZATION-------------------------*/
class Solution {
public:
    int helper(string s, string t, int i, int j, vector<vector<int>>& dp)
    {
        if(j<0)
        {
            return 1;
        }
        if(i<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j] = helper(s,t, i-1, j-1, dp) + helper(s, t, i-1, j, dp);
        }
        return dp[i][j] = helper(s, t, i-1, j, dp);
    }
    int numDistinct(string s, string t) 
    {
        int i = s.size()-1;
        int j = t.size()-1;
        vector<vector<int>> dp(i+1, vector<int>(j+1, -1));
        return helper(s, t, i, j, dp);    
    }
};