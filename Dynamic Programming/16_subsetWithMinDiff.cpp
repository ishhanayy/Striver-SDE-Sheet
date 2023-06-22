//PROBLEM STATEMENT : https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0

/*------------------------USING TABULATION-----------------------------------*/
#include <iostream>
#include <vector>
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n) 
{
    int total_sum=0;
    for (int i=0; i<n; i++) 
    {
        total_sum+=arr[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(total_sum+1, false));
    for (int i=0; i<=n; i++) 
    {
        dp[i][0] = true;
    }

    if(arr[0] <= total_sum) 
    {
        dp[0][arr[0]] = true;
    }

    for(int i=1; i<n; i++) 
    {
        for(int j=1; j<=total_sum; j++) 
        {
            bool take = false;
            if(j>=arr[i]) 
			{
                take = dp[i-1][j-arr[i]];
            }
            bool not_take = dp[i-1][j];
            dp[i][j] = take||not_take;
        }
    }

    int minimum = 1e9;
    for(int i=0; i<=total_sum; i++) 
	{
        if (dp[n-1][i]) 
		{
            minimum = min(minimum, abs((total_sum-i)-i));
        }
    }

    return minimum;
}
