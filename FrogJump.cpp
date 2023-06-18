/*--------------------------------------------------------RECURSION-------------------------------------------------------------------*/
// #include <iostream>
// #include <vector>
// using namespace std;
// int frogJump(vector<int>& height,int n)
// {
//     if(n==0)
//     {
//         return 0;
//     }
//     int one_jump = frogJump(height, n-1) + abs(height[n]-height[n-1]);
//     int two_jump = INT_MAX;
//     if(n>1){
//         two_jump = frogJump(height, n-2) + abs(height[n]-height[n-2]);
//     }
//     return min(one_jump, two_jump);
// }
// int main() {
//     int n; //n is number of stairs
//     cout<<"Enter the number of staris : ";
//     cin>>n;
//     vector<int> height(n);
//     cout<<"Enter the Height of each stair: ";
//     for(int i =0; i<n; i++)
//     {
//         int temp; cin>>temp;
//         height.push_back(temp);
//     }
//     int ans  = frogJump(height, n);
//     cout<<"The minimum energy required by frog to jump "<<n<<" staris is : "<<ans<<"."<<endl;
//     return 0;
// }


/*-----------------------------------------------------MEMOIZATION--------------------------------------------------------------------*/
// #include <iostream>
// #include <vector>

// using namespace std;
// int frogJump(vector<int>& height, vector<int>& dp, int n)
// {
//     if(n<=0)
//     {
//         return 0;
//     }
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     int one_jump = frogJump(height, dp, n-1) + abs(height[n]-height[n-1]);
//     int two_jump = frogJump(height, dp, n-2) + abs(height[n]-height[n-2]);
//     return dp[n] = min(one_jump, two_jump);
// }
// int main() {
//     int n; //n is number of stairs
//     cout<<"Enter the number of staris : ";
//     cin>>n;
//     vector<int> height(n);
//     cout<<"Enter the Height of each stair: ";
//     for(int i =0; i<n; i++)
//     {
//         int temp; cin>>temp;
//         height.push_back(temp);
//     }
//     vector<int> dp(n+1, -1);
//     int ans  = frogJump(height, dp, n);
//     cout<<"The minimum energy required by frog to jump "<<n<<" staris is : "<<ans<<"."<<endl;
//     return 0;
// }


/*------------------------------------------TABULTED FORM------------------------------------------------------------------*/
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n; //n is number of stairs
//     cout<<"Enter the number of staris : ";
//     cin>>n;
//     vector<int> height(n);
//     cout<<"Enter the Height of each stair: ";
//     for(int i =0; i<n; i++)
//     {
//         int temp; cin>>temp;
//         height.push_back(temp);
//     }
//     vector<int> dp(n, -1);
//     dp[0] = 0;
//     dp[1] = 0;
//     for(int i =1; i<n; i++)
//     {
//         int a = dp[i-1]+abs(height[i]-height[i-1]);
//         int b = dp[i-2]+abs(height[i]-height[i-2]);
//         dp[i] = min(a, b);

//     }
//     cout<<"The minimum energy required by frog to jump "<<n<<" staris is : "<<dp[n-1]<<"."<<endl;
//     return 0;
// }


/*-----------------------------------------------MORE OPTIMIZED------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; //n is number of stairs
    cout<<"Enter the number of staris : ";
    cin>>n;
    vector<int> height(n);
    cout<<"Enter the Height of each stair: ";
    for(int i =0; i<n; i++)
    {
        int temp; cin>>temp;
        height.push_back(temp);
    }
    int prev2 = 0;
    int prev1 = 0;
    int ans =0;
    for(int i =1; i<n; i++)
    {
        int a = prev1+abs(height[i]-height[i-1]);
        int b = INT_MAX;
        if(i>1){
            b = prev2+abs(height[i]-height[i-2]);
        }
        ans = min(a,b);
        prev2 = prev1;
        prev1 = ans;
    }
    cout<<"The minimum energy required by frog to jump "<<n<<" staris is : "<<ans<<"."<<endl;
    return 0;
}