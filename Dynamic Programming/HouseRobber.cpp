// PROBLEM : https://www.codingninjas.com/codestudio/problems/house-robber-ii_839733?leftPanelTab=1
/*---------------RECURSION--------------------------*/
#include <bits/stdc++.h> 
long long int helper(vector<int>& nums, int n)
{
    if(n==0)
    {
        return nums[n];
    }
    if(n<0)
    {
        return 0;
    }
    long long int pick = nums[n]+helper(nums, n-2); // n-2 so that we can avoid adjacent element
    long long int not_pick = 0+helper(nums, n-1);
    return max(pick, not_pick);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size()==1)
    {
        return valueInHouse[0];
    }
    vector<int> temp1, temp2;
    for(int i =0; i<valueInHouse.size(); i++)
    {
        if(i!=0)
        {
            temp1.push_back(valueInHouse[i]);
        }
        if(i!=valueInHouse.size()-1)
        {
            temp2.push_back(valueInHouse[i]);
        }
    }
    long long int ans = max(helper(temp1, temp1.size()-1), helper(temp2, temp2.size()-1));
    return ans;
}


/*--------------------MEMOIZAITON---------------------*/
#include <bits/stdc++.h> 
long long int helper(vector<int>& nums, vector<int> dp, int n)
{
    if(n==0)
    {
        return nums[n];
    }
    if(n<0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    long long int pick = nums[n]+helper(nums, dp, n-2); // n-2 so that we can avoid adjacent element
    long long int not_pick = 0+helper(nums, dp, n-1);
    return dp[n] = max(pick, not_pick);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size()==1)
    {
        return valueInHouse[0];
    }
    vector<int> temp1, temp2;
    for(int i =0; i<valueInHouse.size(); i++)
    {
        if(i!=0)
        {
            temp1.push_back(valueInHouse[i]);
        }
        if(i!=valueInHouse.size()-1)
        {
            temp2.push_back(valueInHouse[i]);
        }
    }
    vector<int> dp(valueInHouse.size(), -1);
    long long int ans = max(helper(temp1, dp, temp1.size()-1), helper(temp2, dp, temp2.size()-1));
    return ans;
}


/*----------------TABULATED-----------------------*/
#include <bits/stdc++.h> 

int helper(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    if (n == 0) {
        return 0;
    } 
    else if (n == 1) {
        return nums[0];
    } 
    else if (n == 2) {
        return max(nums[0], nums[1]);
    }
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i<n; i++)
    {
        long long int pick = nums[i]+dp[i-2];
        long long int not_pick = dp[i-1];
        dp[i] = max(pick, not_pick);
    }
    return dp[n-1];
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size()==1)
    {
        return valueInHouse[0];
    }
    vector<int> temp1, temp2;
    for(int i =0; i<valueInHouse.size(); i++)
    {
        if(i!=0)
        {
            temp1.push_back(valueInHouse[i]);
        }
        if(i!=(valueInHouse.size()-1))
        {
            temp2.push_back(valueInHouse[i]);
        }
    }
    long long int ans = max(helper(temp1), helper(temp2));
    return ans;
}


/*----------------MORE OPTIMIZED-----------------------*/
#include <bits/stdc++.h> 

int helper(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    if (n == 0) {
        return 0;
    } 
    else if (n == 1) {
        return nums[0];
    } 
    else if (n == 2) {
        return max(nums[0], nums[1]);
    }
    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    int ans =0;
    for(int i = 2; i<n; i++)
    {
        long long int pick = nums[i]+prev2;
        long long int not_pick = prev1;
        ans = max(pick, not_pick);
        prev2 = prev1;
        prev1 = ans;
    }
    return ans;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    if(valueInHouse.size()==1)
    {
        return valueInHouse[0];
    }
    vector<int> temp1(valueInHouse.begin(), valueInHouse.end() - 1);
    vector<int> temp2(valueInHouse.begin() + 1, valueInHouse.end());
    long long int ans = max(helper(temp1), helper(temp2));
    return ans;
}