//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/partition-equal-subset-sum-_892980?leftPanelTab=0

/*-------------------------RECURSION----------------*/
bool helper(vector<int>& arr, int n, int sum)
{
	if(sum==0)
	{
		return true;
	}
	if(n==0)
	{
		return arr[n]==sum;
	}
	bool take = false;
	if(sum>=arr[n])
	{
		take = helper(arr, n-1, sum-arr[n]);
	}
	bool not_take = helper(arr, n-1, sum);
	return take||not_take;
}

bool canPartition(vector<int> &arr, int n)
{
	int sum =arr[0];
	for(int i = 1; i<n; i++)
	{
		sum+=arr[i];
	}
	if(sum%2!=0)
	{
		return false;
	}
	else
	{
		return helper(arr, n, sum/2);
	}
}


/*----------------------MEMOIZATION----------------*/
bool helper(vector<int>& arr, int n, int sum, vector<vector<bool>>& dp)
{
    if (sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return arr[n] == sum;
    }
    if (dp[n][sum] != false)
    {
        return dp[n][sum];
    }
    bool take = false;
    if (sum >= arr[n])
    {
        take = helper(arr, n - 1, sum - arr[n], dp);
    }
    bool not_take = helper(arr, n - 1, sum, dp);
    return dp[n][sum] = take || not_take;
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    else
    {
        vector<vector<bool>> dp(n + 1, vector<bool>((sum / 2) + 1, false));
        return helper(arr, n - 1, sum / 2, dp);
    }
}


/*-------------------------TABULATION----------------*/
bool canPartition(vector<int> &arr, int n)
{
	int sum =0;
	for(int i = 0; i<n; i++)
	{
		sum+=arr[i];
	}
	if(sum%2!=0)
	{
		return false;
	}
	else
	{
		sum = sum/2;
		vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
		for(int i =0; i<n; i++)
		{
			dp[i][0] = true;
		}
		if(arr[0]<=sum)
		{
			dp[0][arr[0]] = true;
		}
		for(int i = 1; i<n; i++)
		{
			for(int j = 1; j<=sum; j++)
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
		return dp[n-1][sum];
	}
}