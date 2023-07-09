//PROBLEM STATEMENT : https://leetcode.com/problems/longest-palindromic-subsequence/


/*----------------------RECURSION----------------*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int helper(string s, string t, int ind1, int ind2)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        if(s[ind1]==t[ind2])
        {
            return 1+helper(s, t, ind1-1, ind2-1);
        }
        return max(helper(s, t, ind1-1, ind2), helper(s, t, ind1, ind2-1));
    }
    int longestPalindromeSubseq(string s) 
    {
        int ind1 = s.size()-1;
        std::string reversed = s;
        std::reverse(reversed.begin(), reversed.end());
        return helper(s, reversed, ind1, ind1);
    }
};


/*----------------------MEMOIZATION----------------*/
class Solution {
public:
    int helper(string s, string t, int ind1, int ind2, vector<vector<int>>& dp)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        if(s[ind1]==t[ind2])
        {
            return 1+helper(s, t, ind1-1, ind2-1, dp);
        }
        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }
        return dp[ind1][ind2] = max(helper(s, t, ind1-1, ind2, dp), helper(s, t, ind1, ind2-1, dp));
    }
    int longestPalindromeSubseq(string s) 
    {
        int ind1 = s.size()-1;
        std::string reversed = s;
        std::reverse(reversed.begin(), reversed.end());
        vector<vector<int>> dp(s.size(), vector<int>(reversed.size(), -1));
        return helper(s, reversed, ind1, ind1, dp);
    }
};


/*----------------------TABULATION----------------*/
class Solution {
public:
    
    int longestPalindromeSubseq(string s) 
    {
        std::string t = s;
        std::reverse(t.begin(), t.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for(int i =0; i<=s.size(); i++)
        {
            dp[i][0]=0;
        }
        for(int j =0; j<=t.size(); j++)
        {
            dp[0][j]=0;
        }
        for(int i = 1; i<=s.size(); i++)
        {
            for(int j =1; j<=t.size(); j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                } 
                else 
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};