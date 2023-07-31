//PROBLEM STATEMENT : https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    int maxi_ele(vector<int>& arr)
    {
        int maxi = 0;
        for(auto i : arr)
        {
            maxi = max(i, maxi);
        }
        return maxi;
    }
    int sum_arr(vector<int>& arr)
    {
        int sum = 0;
        for(auto i : arr)
        {
            sum+=i;
        }
        return sum;
    }
    int num_of_subArray(vector<int>& arr, int len)
    {
        int subArray = 1;
        int l = 0;
        for(auto i : arr)
        {
            if((i+l)<=len)
            {
                l+=i;
            }
            else
            {
                subArray++;
                l = i;
            }
        }
        return subArray;
    }
    int splitArray(vector<int>& nums, int k)
    {
        int low = maxi_ele(nums);
        int high = sum_arr(nums);
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int sub_arr = num_of_subArray(nums, mid);
            if(sub_arr>k)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return low;
    }
};