//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1

#include <bits/stdc++.h> 

int canYouMake(string s, string t) 
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
	return s.size()+t.size()-2*dp[s.size()][t.size()];    
} 