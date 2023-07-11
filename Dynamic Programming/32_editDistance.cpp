//PROBLEM STATMENT : https://leetcode.com/problems/edit-distance/

/*------------------------RECURSION------------------------*/
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    int helper(string s, string t, int i, int j)
    {
        if(i<0) //it means that s string is being exhausted
        {
            return j+1;
        }
        if(j<0) //it means that t string is being exhausted
        {
            return i+1;
        }
        if(s[i]==t[j])
        {
            return 0+helper(s, t, i-1, j-1);
        }
        else
        {
            int insert = helper(s, t, i, j-1);
            int delet_e = helper(s, t, i-1, j);
            int replace = helper(s, t, i-1, j-1);
            return 1+min(insert, min(delet_e, replace));
        }
    }
    int minDistance(string s, string t) 
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
        if(i<0) //it means that s string is being exhausted
        {
            return j+1;
        }
        if(j<0) //it means that t string is being exhausted
        {
            return i+1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==t[j])
        {
            return dp[i][j] = helper(s, t, i-1, j-1, dp);
        }
        else
        {
            int insert = helper(s, t, i, j-1, dp);
            int delet_e = helper(s, t, i-1, j, dp);
            int replace = helper(s, t, i-1, j-1, dp);
            return dp[i][j] = 1+min(insert, min(delet_e, replace));
        }
    }
    int minDistance(string s, string t) 
    {
        int i = s.size()-1;
        int j = t.size()-1; 
        vector<vector<int>> dp(i+1, vector<int>(j+1, -1));
        return helper(s, t, i, j, dp);
    }
};