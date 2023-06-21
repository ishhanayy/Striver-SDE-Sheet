//Problem Statement : https://www.codingninjas.com/studio/problems/merge-sort_920442?leftPanelTab=1

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int l, int mid, int r)
{
    vector<int> temp;
    int i = l;
    int j = mid+1;
    while(i<=mid && j<=r)
    {
        if(arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=r)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=l; k<=r; k++) 
    {
        arr[k] = temp[k-l]; 
    }
}

void helper(vector<int>& arr, int l, int r)
{
    if(l>=r)
    {
        return;
    }
    int mid = (l+r)/2;
    helper(arr, l, mid);
    helper(arr, mid+1, r);
    merge(arr, l, mid, r);
}

void mergeSort(vector<int>& arr, int n)
{
    int l = 0;
    int r = n - 1;
    helper(arr, l, r);
}
