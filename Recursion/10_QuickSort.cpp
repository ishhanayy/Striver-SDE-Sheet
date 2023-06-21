//Problem Statement : https://www.codingninjas.com/studio/problems/merge-sort_920442?leftPanelTab=1

#include <iostream>
#include <vector>
using namespace std;
int helper1(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(j>i)
    {
        while(arr[i]<=pivot && i<=high)
        {
            i++;
        }
        while(arr[j]>pivot && j>=low)
        {
            j--;
        }
        if(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}
void helper(vector<int>& arr, int low, int high)
{
    if(low<high)
    {
        int partition_index = helper1(arr, low, high);
        helper(arr, low, partition_index-1);
        helper(arr, partition_index+1, high);
    }
}
vector<int> quickSort(vector<int> arr)
{
    int low = 0;
    int high = arr.size()-1;
    helper(arr, low, high);
    return arr;
}