/*Printing the sum using parametrized way*/
#include <iostream>
using namespace std;
void helper(int n, int sum =0)
{
    if(n==0)
    {
        cout<<sum<<endl;
        return;
    }
    helper(n-1, sum+n);
}
int main() {
    int n;
    cout<<"Enter the num till you want sum from 1 : ";
    cin>>n;
    cout<<endl;
    helper(n);
    return 0;
}


/*Printing the sum using functional way*/
#include <iostream>
using namespace std;
int helper(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n+helper(n-1);
}
int main() {
    int n;
    cout<<"Enter the num till you want sum from 1 : ";
    cin>>n;
    cout<<endl;
    int sum = helper(n);
    cout<<"The sum of n numbers is : "<<sum<<endl;
    return 0;
}