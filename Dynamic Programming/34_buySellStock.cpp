//PROBLEM STATEMENT : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result =0;
        int buy = prices[0];
        for(int i =1; i<prices.size(); i++)
        {
            buy = min(buy, prices[i]);
            result = max(result, prices[i]-buy);
        }
        return result;
    }
};