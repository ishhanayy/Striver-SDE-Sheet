/* Fibonacci is a number series whose current numberr is the sum of two previous value, and that's why the first two number are already fixed or we can say the base value i.e., 0th indexed num is 0 and 1st indexed num is 1.*/

/*-----------------------------------------BRUTE FORCE------------------------------------------------------------*/
// #include <iostream>
// using namespace std;

// int fibonacci(int n)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     int small_output = fibonacci(n-1)+fibonacci(n-2);
//     return small_output;
// }
// int main() {
//     int n; //The  number you want the fibonacci of!
//     cout<<"Enter the Number : ";
//     cin>>n;
//     int ans = fibonacci(n);
//     cout<<"\nThe fibonacci num of nth term is : "<<ans<<"."<<endl;
//     return 0;
// }


/*-----------------------------------------------MEMOIZATION--------------------------------------------------------------*/
// #include <iostream>
// #include <vector>
// using namespace std;
// int fibonacci(vector<int>& dp,int n)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     return dp[n] = fibonacci(dp, n-1)+fibonacci(dp, n-2);
// }
// int main() {
//     int n; //The  number you want the fibonacci of!
//     cout<<"Enter the Number : ";
//     cin>>n;
//     vector<int> dp(n+1, -1); //To store the computed value;
//     int ans = fibonacci(dp, n);
//     cout<<"\nThe fibonacci num of nth term is : "<<ans<<"."<<endl;
//     return 0;
// }


/*--------------------------------------------------TABULATED FORM--------------------------------------------------------------------*/
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int n; //The  number you want the fibonacci of!
//     cout<<"Enter the Number : ";
//     cin>>n;
//     vector<int> dp(n+1, -1); //To store the computed value;
//     dp[0] = 0;
//     dp[1] = 1;
//     for(int i =2; i<=n; i++)
//     {
//         dp[i] = dp[i-1]+dp[i-2];
//     }
//     cout<<"\nThe fibonacci num of nth term is : "<<dp[n]<<"."<<endl;
//     return 0;
// }


/*--------------------------------------------------MORE OPTIMIZED----------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int n; //The  number you want the fibonacci of!
    cout<<"Enter the Number : ";
    cin>>n;
    int prev2 =0;
    int prev1 =1;
    int ans;
    for(int i =2; i<=n; i++)
    {
        ans = prev1+prev2;
        prev2 = prev1;
        prev1 = ans;
    }
    cout<<"\n The fibonacci num of nth term is : "<<ans<<"."<<endl;
    return 0;
}  

