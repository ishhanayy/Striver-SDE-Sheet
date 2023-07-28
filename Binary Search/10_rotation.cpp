//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/rotation_7449070?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTab=0

#include <vector>
int findKRotation(vector<int> &arr)
{
    //it is similar to the question which tells the minimum element in the array
    int low =0;
    int high = arr.size()-1;
    int ans = 1e9;
    int ind =-1;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(arr[mid]<=arr[high])
        {
            if(arr[mid]<ans)
            {
                ans = arr[mid];
                ind = mid;
            }
            high = mid-1;
        }
        else
        {
            if(arr[low]<ans)
            {
                ans = arr[low];
                ind = low;
            }
            low = mid+1;
        }
    }    
    return ind;
}