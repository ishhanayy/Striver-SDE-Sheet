#include <iostream>
#include <vector>
using namespace std;
void helper(vector<int>& arr, int i, vector<int>& ans)
{
    if(i==arr.size())
    {
        for(auto it : ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[i]);
    helper(arr, i+1, ans);
    ans.pop_back();
    helper(arr, i+1, ans);
}
int main() {
    int n; // n will be the size of the array
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<endl;
    vector<int> arr(n);
    cout<<"Enter the element of the array : ";
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
    vector<int> ans;
    helper(arr, 0, ans);
    return 0;
}