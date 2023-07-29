//PROBLEM STATEMENT : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int maxi_ele(vector<int>& weights)
    {
        int maxi = INT_MIN;
        for(int i =0; i<weights.size(); i++)
        {
            maxi = max(maxi, weights[i]);
        }
        return maxi;
    }
    int TotalSum(vector<int>& weights)
    {
        int sum = 0;
        for(int i =0; i<weights.size(); i++)
        {
            sum+=weights[i];
        }
        return sum;
    }
    int TotalNumOfDays(vector<int>& weights, int capacity)
    {
        int day = 1;
        int load =0;
        for(int i =0; i<weights.size(); i++)
        {
            if(load+weights[i]>capacity)
            {
                day+=1;
                load = weights[i];
            }
            else
            {
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = maxi_ele(weights);
        int high = TotalSum(weights);
        int ans = 0;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int num_days = TotalNumOfDays(weights, mid);  // mid is determininf the capacity
            if(num_days<=days)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};