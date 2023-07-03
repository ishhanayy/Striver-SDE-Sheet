//PROBLEM STATEMENT: https://www.codingninjas.com/studio/problems/longest-common-substring_1214702?leftPanelTab=1


#include <iostream>
#include <vector>
#include <string>
using namespace std;
int LCSubStr(string &s, string &t)
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
    int ans = 0;
	for(int i = 1; i<=s.size(); i++)
	{
		for(int j =1; j<=t.size(); j++)
		{
			if(s[i-1]==t[j-1])
			{
				dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            } 
			else 
			{
                dp[i][j] = 0;
            }
        }
	}
	return ans;

}