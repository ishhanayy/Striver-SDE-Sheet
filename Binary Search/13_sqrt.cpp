//PROBLEM STATEMENT : https://leetcode.com/problems/sqrtx/

//Binary Search
class Solution {
public:
    int mySqrt(int x) 
    {
        int low = 1;
        int high = x;
        long long ans = 0;
        while(low<=high)
        {
            long long mid = low+(high-low)/2;
            long long val = mid*mid;
            if(val>x)
            {
                high = mid-1;
            }
            else
            {
                ans = mid;
                low = mid+1;
            }
        }    
        return ans;
    }
};
