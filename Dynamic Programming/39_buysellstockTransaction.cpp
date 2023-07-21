//PROBLEM STATEMENT : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

/*------------------------RECURSION------------------------*/
#include <iostream>
#include <vector>
#include <climit>
class Solution {
public:
    int helper(vector<int>& prices, int i, int buy, int fee)
    {
        if(i==prices.size())
        {
            return 0;
        }
        int profit = 0;
        if(buy==1)
        {
            int buy_it = -prices[i]+helper(prices, i+1, 0, fee); // if we have buyed then now we have to sell it
            int not_buy = 0 + helper(prices, i+1, 1, fee); // we haven't buyed it.
            profit = max(buy_it, not_buy);
        }
        else
        {
            int sell_it = prices[i]-fee+helper(prices, i+1, 1, fee); // we have selled it
            int not_sell = 0+helper(prices, i+1, 0, fee); // we haven't sell it 
            profit = max(sell_it, not_sell);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) 
    {
        int i =0;
        int buy = 1; // if buy is flagged 1, then we can buy the stock but if it is flagged 0, then we cannnot buy it.
        return helper(prices, i, buy, fee);    
    }
};


/*----------------------MEMOIZATION----------------*/
class Solution {
public:
    int helper(vector<int>& prices, int i, int buy, vector<vector<int>>& dp, int fee)
    {
        if(i==prices.size())
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
            int buy_it = -prices[i]+helper(prices, i+1, 0, dp, fee); // if we have buyed then now we have to sell it
            int not_buy = 0 + helper(prices, i+1, 1, dp, fee); // we haven't buyed it.
            profit = max(buy_it, not_buy);
        }
        else
        {
            int sell_it = prices[i]-fee+helper(prices, i+1, 1, dp, fee); // we have selled it
            int not_sell = 0+helper(prices, i+1, 0, dp, fee); // we haven't sell it 
            profit = max(sell_it, not_sell);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) 
    {
        int i =0;
        int buy = 1; // if buy is flagged 1, then we can buy the stock but if it is flagged 0, then we cannnot buy it.
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices, i, buy, dp, fee);    
    }
};


/*----------------------TABULATION----------------*/
class Solution {
public:

    int maxProfit(vector<int>& prices, int fee) 
    {
        
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));   

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
                        int sell_it = prices[i]-fee+dp[i+1][1]; // we have selled it
                        int not_sell = 0+dp[i+1][0]; // we haven't sell it 
                        dp[i][buy] = max(sell_it, not_sell);
                    }
                
            }
        }
        return dp[0][1];
    }
};