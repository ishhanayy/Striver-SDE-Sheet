#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lengthOfLIS(vector<int> &nums, vector<int>& bt, int& ind_of_max_ele)
{
    int maxi = 0;
    vector<int> ans(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                ans[i] = max(ans[i], 1 + ans[j]);
                ind_of_max_ele = i;
                bt[i] = j;
            }
        }
        if(ans[i]>maxi)
        {
            maxi = ans[i];
            ind_of_max_ele = i;
        }
    }
    return maxi;
}

int main()
{
    cout<<"Enter the size of the array : "<<endl;
    int n;
    cin>>n;
    vector<int> nums;
    vector<int> bt(n, -1);
    int ind_of_max_ele = 0;
    cout<<"Enter the elements of the array : "<<endl;
    for(int i =0; i<n; i++)
    {
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    cout<<"What can be the length it's longest increasing subsequence : "<<endl;
    int length  = lengthOfLIS(nums, bt, ind_of_max_ele);
    cout<<length<<endl;
    cout<<"What can be it's longest increasing subsequence : "<<endl;
    vector<int> store;
    int i = ind_of_max_ele;
    while(i>=0)
    {
        store.push_back(nums[i]);
        i = bt[i];
    }
    for(int i = store.size()-1; i>=0; i--)
    {
        cout<<store[i]<<" ";
    }
}
