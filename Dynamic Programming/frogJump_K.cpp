/*Problem Statement : 
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is h(i).
There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:
If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. Here, a cost of ∣h(i)−h(j)∣ is incurred, where j is the stone to land on.Find the minimum possible total cost incurred before the frog reaches Stone N.*/

/*------------------------------------------------RECURSION------------------------------------------------------------------------------*/
// #include <iostream>
// #include <vector>
// #include <cstdlib>
// using namespace std;
// int FrogJumpK(vector<int> height, int n, int k)
// {
//     if(n==0)
//     {
//         return 0;
//     }
//     int final_min = INT_MAX;
//     int minimum = INT_MAX;
//     for(int j =1; j<=k; j++) //To make from 1 jump upto k one.
//     {
//         if(n-j>=0)
//         {
//             minimum = FrogJumpK(height, n-j, k) + abs(height[n]-height[n-j]);
//         }
//         final_min = min(final_min, minimum);
//     }
//     return final_min;
// }
// int main() {
//     int n; //n is number of stairs
//     cout<<"Enter the number of staris : ";
//     cin>>n;
//     int k; //n is number of stairs
//     cout<<"Enter the number of jump frog can make : ";
//     cin>>k;
//     vector<int> height(n);
//     cout<<"Enter the Height of each stair: ";
//     for(int i =0; i<n; i++)
//     {
//         int temp; cin>>temp;
//         height.push_back(temp);
//     }
//     int ans = FrogJumpK(height, n, k);
//     cout<<"The minimum energy required by frog to jump "<<n<<" staris is : "<<ans<<"."<<endl;
//     return 0;
// }


/*---------------------------------------------------MEMOIZATION------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int FrogJumpK(vector<int> height, vector<int> dp, int n, int k)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int final_min = INT_MAX;
    int minimum = INT_MAX;
    for(int j =1; j<=k; j++) //To make from 1 jump upto k one.
    {
        if(n-j>=0)
        {
            minimum = FrogJumpK(height, dp, n-j, k) + abs(height[n]-height[n-j]);
        }
        final_min = min(final_min, minimum);
        dp[n] = final_min;
    }
    return dp[n];
}
int main() {
    int n; //n is number of stairs
    cout<<"Enter the number of staris : ";
    cin>>n;
    int k; //n is number of stairs
    cout<<"Enter the number of jump frog can make : ";
    cin>>k;
    vector<int> height(n);
    cout<<"Enter the Height of each stair: ";
    for(int i =0; i<n; i++)
    {
        int temp; cin>>temp;
        height.push_back(temp);
    }
    vector<int> dp(n, -1);
    int ans = FrogJumpK(height, dp, n, k);
    cout<<"The minimum energy required by frog to jump "<<n<<" staris is : "<<ans<<"."<<endl;
    return 0;
}