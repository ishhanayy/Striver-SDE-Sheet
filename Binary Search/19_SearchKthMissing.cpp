//PROBLEM STATEMENT : https://leetcode.com/problems/kth-missing-positive-number/

//Brute force approach
//TIme complexity : O(N)
//Space complexity : O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        for(int i = 0; i<arr.size(); i++)
        {
            if(arr[i]<=k)
            {
                k++;
            }
            else
            {
                break;
            }
        }   
        return k; 
    }
};

//Binary Search 
//Time Complexity : O(logn)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int low = 0;
        int high = arr.size()-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int missing = arr[mid]-(mid+1);
            if(missing<k)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return (high+1+k);
    }
};