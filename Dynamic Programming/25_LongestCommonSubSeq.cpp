//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

/*----------------------RECURSION----------------*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
int lcs(string s, string t)
{
	//Write your code here
	int ind1 = s.size()-1;
	int ind2 = t.size()-1;
	return helper(s, t, ind1, ind2);
}


/*----------------------MEMOIZATION----------------*/
#include <vector>
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
int lcs(string s, string t)
{
	//Write your code here
	int ind1 = s.size()-1;
	int ind2 = t.size()-1;
	vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
	return helper(s, t, ind1, ind2, dp);
}


/*----------------------TABULATION----------------*/
int lcs(string s, string t)
{
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