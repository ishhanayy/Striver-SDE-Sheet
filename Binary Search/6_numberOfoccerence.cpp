//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
//very similar to the 5th one
int helper_first(vector<int>& nums, int target)
    {
        int low = 0; 
        int high = nums.size()-1;
        int ans = -1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid]>target)
            {
                high = mid-1; //smallest (right search space will be eliminated)
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
int helper_last(vector<int>& nums, int target)
    {
        int low = 0; 
        int high = nums.size()-1;
        int ans = -1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]>target)
            {
                high = mid-1; 
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
int count(vector<int>& nums, int n, int target) {
	// Write Your Code Here
	int first = helper_first(nums, target);
	if(first == -1)
	{
		return 0;
	}
    else
	{
		int last  = helper_last(nums, target);
		return last-first+1;
	}
}

