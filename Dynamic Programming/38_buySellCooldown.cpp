//PROBLEM STATEMENT : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

/*------------------------RECURSION------------------------*/
#include <iostream>
#include <vector>
#include <climit>
class Solution {
public:
    int helper(vector<int>& prices, int i, int buy)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        int profit = 0;
        if(buy==1)
        {
            int buy_it = -prices[i]+helper(prices, i+1, 0); // if we have buyed then now we have to sell it
            int not_buy = 0 + helper(prices, i+1, 1); // we haven't buyed it.
            profit = max(buy_it, not_buy);
        }
        else
        {
            int sell_it = prices[i]+helper(prices, i+2, 1); // we have selled it
            int not_sell = 0+helper(prices, i+1, 0); // we haven't sell it 
            profit = max(sell_it, not_sell);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int i =0;
        int buy = 1; // if buy is flagged 1, then we can buy the stock but if it is flagged 0, then we cannnot buy it.
        return helper(prices, i, buy);    
    }
};


/*----------------------MEMOIZATION----------------*/
class Solution {
public:
    int helper(vector<int>& prices, int i, int buy, vector<vector<int>>& dp)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        if(dp[i][buy]!=-1)
        {
            return dp[i][buy];
        }
        int profit = 0;
        if(buy==1)
        {
            int buy_it = -prices[i]+helper(prices, i+1, 0, dp); // if we have buyed then now we have to sell it
            int not_buy = 0 + helper(prices, i+1, 1, dp); // we haven't buyed it.
            profit = max(buy_it, not_buy);
        }
        else
        {
            int sell_it = prices[i]+helper(prices, i+2, 1, dp); // we have selled it
            int not_sell = 0+helper(prices, i+1, 0, dp); // we haven't sell it 
            profit = max(sell_it, not_sell);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int i =0;
        int buy = 1; // if buy is flagged 1, then we can buy the stock but if it is flagged 0, then we cannnot buy it.
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices, i, buy, dp);    
    }
};


/*----------------------TABULATION----------------*/
class Solution {
public:

    int maxProfit(vector<int>& prices) 
    {
        
        vector<vector<int>> dp(prices.size()+2, vector<int>(2, 0));   

        for(int i = prices.size()-1; i>=0; i--)
        {
            for(int buy =0; buy<2; buy++)
            {
                
                
                    if(buy==1)
                    {
                        int buy_it = -prices[i]+dp[i+1][0]; // if we have buyed then now we have to sell it
                        int not_buy = 0 + dp[i+1][1]; // we haven't buyed it.
                        dp[i][buy] = max(buy_it, not_buy);
                    }
                    else
                    {
                        int sell_it = prices[i]+dp[i+2][1]; // we have selled it
                        int not_sell = 0+dp[i+1][0]; // we haven't sell it 
                        dp[i][buy] = max(sell_it, not_sell);
                    }
                
            }
        }
        return dp[0][1];
    }
};