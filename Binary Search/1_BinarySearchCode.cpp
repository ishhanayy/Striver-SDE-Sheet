//PROBLEM STATEMENT : https://leetcode.com/problems/binary-search/

/*----------------------ITERATIVE---------------------------*/
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(target>nums[mid])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        } 
        return -1;   
    }
};


/*----------------------RECURSIVE---------------------------*/
class Solution {
public:
    int helper(vector<int>& nums, int low, int high, int target)
    {
        if(low>high)
        {
            return -1;
        }
        int mid = (low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]>target)
        {
            return helper(nums, low, mid-1, target);
        }
        else
        {
            return helper(nums, mid+1, high, target);
        }
    }
    int search(vector<int>& nums, int target) 
    {
        int low =0;
        int high = nums.size()-1;
        return helper(nums, low, high, target);  
    }
};