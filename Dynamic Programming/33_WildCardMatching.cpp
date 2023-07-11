//PROBLEM STATEMENT : https://leetcode.com/problems/wildcard-matching/

/*----------------------RECURSION----------------*/
#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
    bool helper(string& s, string& p, int i, int j)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i>=0 && j<0)
        {
            return false;
        }
        if(i<0 && j>=0)
        {
            for(int k = 0; k<=j; k++)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(s[i]==p[j] || p[j]=='?') 
        {
            return helper(s, p, i-1, j-1);
        }
        if(p[j]=='*')
        {
            return (helper(s, p, i-1, j) || helper(s, p, i, j-1)) ; //not considering the * OR considering the *
        }

        //in the pattern string the character with the character of s string is nither matching nor * or ? 
        //then definately it will not form the pattern of the s string and we can simply return false
        return false; 
        
    }
    bool isMatch(string s, string p) 
    {
        int i = s.size();
        int j = p.size();
        return helper(s, p, i-1, j-1);    
    }
};


/*----------------------MEMOIZATION----------------*/
class Solution {
public:
    bool helper(string& s, string& p, int i, int j, vector<vector<int>>& dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i>=0 && j<0)
        {
            return false;
        }
        if(i<0 && j>=0)
        {
            for(int k = 0; k<=j; k++)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?') 
        {
            return dp[i][j] = helper(s, p, i-1, j-1, dp);
        }
        if(p[j]=='*')
        {
            return dp[i][j] = (helper(s, p, i-1, j, dp) || helper(s, p, i, j-1, dp)) ; //not considering the * OR considering the *
        }

        //in the pattern string the character with the character of s string is nither matching nor * or ? 
        //then definately it will not form the pattern of the s string and we can simply return false
        return dp[i][j] = false; 
        
    }
    bool isMatch(string s, string p) 
    {
        int i = s.size();
        int j = p.size();
        vector<vector<int>> dp(i, vector<int>(j, -1));
        return helper(s, p, i-1, j-1, dp);    
    }
};