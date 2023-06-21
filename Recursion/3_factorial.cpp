/*Write a function to return the factorial pf a number in recursive way*/

#include <iostream>
using namespace std;
int helper(int n)
{
    if(n == 1)
    {
        return 1;
    }
    return n*helper(n-1);
}
int main() {
    int n;
    cout<<"Enter the number to print it's factorial : ";
    cin>>n;
    cout<<endl;
    int ans = helper(n);
    cout<<"The factorial of "<<n<<" is : "<<ans<<endl;
    return 0;
}