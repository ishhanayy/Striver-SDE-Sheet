//PROBLEM STATEMENT : https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int max_element(vector<int>& arr)
    {
        int maxi =INT_MAX;
        for(int i =0; i<arr.size(); i++)
        {
            maxi= max(maxi, arr[i]);
        }
        return maxi;
    }
    long long eaten_per_pile(vector<int>& piles, int mid)
    {
        long long  total_hour = 0;
        for(int i =0; i<piles.size(); i++)
        {
            total_hour+=ceil(double(piles[i])/double(mid));
        }
        return total_hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1; //since the least number of banana eaten per hour shoul be atleast one.
        int high = max_element(piles);  // it is the maximum number of banana can be eaten per hour
        int ans = INT_MAX;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            long long total_hour = eaten_per_pile(piles, mid);
            if(total_hour<=h)
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