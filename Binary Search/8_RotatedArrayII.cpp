//PROBLEM STATEMENT : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    int helper(vector<int>& nums, int target) 
    {
        int low = 0;   
        int high = nums.size()-1;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[mid]==nums[low] && nums[mid]==nums[high])
            {
                low = low+1;
               high = high-1;
               continue;
            }
            
            if(nums[mid]<=nums[high])
            {
                if(nums[mid]<=target && target<=nums[high])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            else
            {
                if(nums[low]<=target && target<=nums[mid])
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
        } 
        return -1;
    }
    bool search(vector<int>& nums, int target) 
    {
        int ans = helper(nums, target);
        return (ans!=-1);
    }
};