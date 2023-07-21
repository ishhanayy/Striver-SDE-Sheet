//PROBLEM STATEMENT : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*----------------------RECURSION----------------*/
class Solution {
public:
    int helper(vector<int>& prices, int i, int buy, int transaction)
    {
        if(transaction==0)
        {
            return 0;
        }
        if(i==prices.size())
        {
            return 0;
        }
        int profit = 0;
        if(buy==1)
        {
            int buy_it = -prices[i]+helper(prices, i+1, 0, transaction); // if we have buyed then now we have to sell it
            int not_buy = 0 + helper(prices, i+1, 1, transaction); // we haven't buyed it.
            profit = max(buy_it, not_buy);
        }
        else
        {
            int sell_it = prices[i]+helper(prices, i+1, 1, transaction-1); // we have selled it
            int not_sell = 0+helper(prices, i+1, 0, transaction); // we haven't sell it 
            profit = max(sell_it, not_sell);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int i =0;
        int buy = 1; // if buy is flagged 1, then we can buy the stock but if it is flagged 0, then we cannnot buy it.
        int transaction = 2;
        return helper(prices, i, buy, transaction);    
    }
};


/*----------------------MEMOIZATION----------------*/
class Solution {
public:
    int helper(vector<int>& prices, int i, int buy, vector<vector<vector<int>>>& dp, int transaction)
    {
        if(transaction==0)
        {
            return 0;
        }
        if(i==prices.size())
        {
            return 0;
        }
        if(dp[i][buy][transaction]!=-1)
        {
            return dp[i][buy][transaction];
        }
        int profit = 0;
        if(buy==1)
        {
            int buy_it = -prices[i]+helper(prices, i+1, 0, dp, transaction); // if we have buyed then now we have to sell it
            int not_buy = 0 + helper(prices, i+1, 1, dp, transaction); // we haven't buyed it.
            profit = max(buy_it, not_buy);
        }
        else
        {
            int sell_it = prices[i]+helper(prices, i+1, 1, dp, transaction-1); // we have selled it
            int not_sell = 0+helper(prices, i+1, 0, dp, transaction); // we haven't sell it 
            profit = max(sell_it, not_sell);
        }
        return dp[i][buy][transaction] = profit;
    }
    int maxProfit(vector<int>& prices) 
    {
        int i =0;
        int buy = 1; // if buy is flagged 1, then we can buy the stock but if it is flagged 0, then we cannnot buy it.
        int transaction = 2;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, i, buy, dp, transaction);    
    }
};


/*----------------------TABULATION----------------*/
class Solution {
public:

    int maxProfit(vector<int>& prices) 
    {
        
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));   

        for(int i = prices.size()-1; i>=0; i--)
        {
            for(int buy =0; buy<2; buy++)
            {
                for(int transaction = 1; transaction<3; transaction++)
                {
                    if(buy==1)
                    {
                        int buy_it = -prices[i]+dp[i+1][0][transaction]; // if we have buyed then now we have to sell it
                        int not_buy = 0 + dp[i+1][1][transaction]; // we haven't buyed it.
                        dp[i][buy][transaction] = max(buy_it, not_buy);
                    }
                    else
                    {
                        int sell_it = prices[i]+dp[i+1][1][transaction-1]; // we have selled it
                        int not_sell = 0+dp[i+1][0][transaction]; // we haven't sell it 
                        dp[i][buy][transaction] = max(sell_it, not_sell);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};