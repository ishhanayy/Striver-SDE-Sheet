/*Multiple Recursion call : It means that in a recursive function the function call itself for more then one time in one go.*/
/*One of the simplest example is Fibonacci series*/
#include <iostream>
int helperfibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    int a=helperfibo(n-1);
    int b=helperfibo(n-2);
    return a+b;
}
using namespace std;
int main() {
    int n;
    cout<<"Enter the nth number of fibonacci series you want to get : ";
    cin>>n;
    cout<<endl;
    int ans = helperfibo(n);
    cout<<"The element at "<<n<<"th "<<"position of fibonacci series is "<<ans<<endl;
    return 0;
}