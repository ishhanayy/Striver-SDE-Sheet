//PROBLEM STATEMENT : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int maxi_ele(vector<int>& nums)
    {
        int maxi = INT_MIN;
        for(int i =0; i<nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }
    bool div_sum(vector<int>& nums, int div, int threshold)
    {
        long long sum = 0;
        for(int i =0; i<nums.size(); i++)
        {
            sum += ceil(double(nums[i])/double(div));
            if(sum>threshold)
            {
                return false;
            }
        }
        if(sum<=threshold)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low = 1;
        int high = maxi_ele(nums);
        int ans = 0;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            bool in_range = div_sum(nums, mid, threshold);
            if(in_range)
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