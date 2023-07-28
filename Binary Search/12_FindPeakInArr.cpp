//PROBLEM STATEMENT : https://leetcode.com/problems/find-peak-element/

//Using the binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return 0;
        }
        int low = 0;
        int high = nums.size()-1;
        if(nums[0]>nums[1])
        {
            return low;
        }
        if(nums[high-1]<nums[high])
        {
            return high;
        }
        low = 1; 
        high = nums.size()-2;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else if(nums[mid-1]<nums[mid])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        } 
        return -1;   //returning hypothetically
    }
};