//PROBLEM STATEMENT : https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) 
    {
        if(arr.size()==1)
        {
            return arr[0];
        }
        int low = 0;
        int high = arr.size()-1;
        if(arr[low]!=arr[low+1])
        {
            return arr[low];
        }
        if(arr[high]!=arr[high-1])
        {
            return arr[high];
        }
        low+=1; high-=1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr[mid]!=arr[mid+1] && arr[mid-1]!=arr[mid])
            {
                return arr[mid];
            }
            if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1])) //element in the right half
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