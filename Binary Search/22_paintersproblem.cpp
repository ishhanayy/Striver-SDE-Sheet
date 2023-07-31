//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?leftPanelTab=1

#include <climits>
int max_ele(vector<int>& arr)
{
    int maxi = INT_MIN;
    for(auto i : arr)
    {
        maxi = max(maxi, i);
    }
    return maxi;
}
int boards_sum(vector<int>& arr)
{
    int sum = 0;
    for(auto i : arr)
    {
        sum+=i;
    }
    return sum;
}
int num_of_painters(vector<int>& arr, int time)
{
    int painters = 1;
    int t = 0; //intially they haven't utilized time
    for(auto i : arr)
    {
        if((i+t)<=time)
        {
            t+=i;
        }
        else
        {
            painters++;
            t = i;
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    if(boards.size()<k)
    {
        return -1;
    }
    int low = max_ele(boards); // it is the minimum time required in which all the boards can be painted
    int high = boards_sum(boards); //it is the maximum time required in which the boards will be painted
    //finding the range in low and high determines that our answer definetly lie between this range
    while(low<=high)
    {
        int mid = low+(high-low)/2; //here mid represent the perticular time
        int painters = num_of_painters(boards, mid); //this function will return the number of painters to which the boards have been allocated and they have painted in the mid interval of time
        if(painters>k)
        {
            low = mid+1; // time kam mila painters ko, isliye jyda number of painters ki requirement hui, but we don't want that that's why increasing the timing
        }
        else
        {
            high = mid-1; //this is just the opposite case of the above one
        }
    }
    return low;
}