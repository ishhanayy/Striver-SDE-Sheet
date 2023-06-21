/*Reverse the array using recursion*/
#include <iostream>
#include <vector>
using namespace std;
void helper(vector<int>& arr, int l, int r)
{
    if(r<=l)
    {
        return;
    }
    int temp = arr[r];
    arr[r] = arr[l];
    arr[l] = temp;
    helper(arr,l+1, r-1);
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
    
    helper(arr, 0, n-1);
    cout<<"The array after reversing is : ";
    for(int i =0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}