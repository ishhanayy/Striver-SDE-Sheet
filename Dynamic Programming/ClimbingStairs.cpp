/*------------------------------------------------RECURSION (BRUTE)----------------------------------------------------------------------*/
// #include <iostream>
// using namespace std;
// int ClimbingStairsWay(int n)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     int one_step = ClimbingStairsWay(n-1);
//     int two_step = ClimbingStairsWay(n-2);
//     return one_step + two_step;
// }
// int main() {
//     int n; // Enter the Number of Stairs
//     cout<<"Enter the Number of Stairs : ";
//     cin>>n;
//     int ans = ClimbingStairsWay(n);
//     cout<<"\nThe no. of possible ways to climb "<<n<<" stairs is : "<<ans<<endl;
//     return 0;
// }


/*-----------------------------------------------------MEMOIZATION-----------------------------------------------------------------------*/
// #include <iostream>
// #include <vector>
// using namespace std;
// int ClimbingStairsWay(vector<int>& vec, int n)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     if(vec[n]!=-1)
//     {
//         return vec[n];
//     }
//     int one_step = ClimbingStairsWay(vec, n-1);
//     int two_step = ClimbingStairsWay(vec, n-2);
//     return vec[n] = one_step + two_step;
// }
// int main() {
//     int n; // Enter the Number of Stairs
//     cout<<"Enter the Number of Stairs : ";
//     cin>>n;
//     vector<int> vec(n+1, -1);
//     int ans = ClimbingStairsWay(vec, n);
//     cout << "\nThe number of possible ways to climb " << n << " stairs is : " << ClimbingStairsWay(vec, n) << endl;
//     return 0;
// }


/*----------------------------------------------TABULATED FORM ------------------------------------------------------------------------*/
// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n; // Enter the Number of Stairs
//     cout<<"Enter the Number of Stairs : ";
//     cin>>n;
//     vector<int> vec(n+1, -1);
//     vec[0] = 1;
//     vec[1] = 1;
//     for(int i = 2; i<=n; i++)
//     {
//         vec[i] = vec[i-1] + vec[i-2];
//     }
//     cout << "\nThe number of possible ways to climb " << n << " stairs is : " << vec[n]<< endl;
//     return 0;
// }


/*-------------------------------------------------MORE OPTIMIZED------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // Enter the Number of Stairs
    cout<<"Enter the Number of Stairs : ";
    cin>>n;
    vector<int> vec(n+1, -1);
    int prev1 = 1;
    int prev2 = 1;
    int ans = 0;
    for(int i = 2; i<=n; i++)
    {
        ans = prev1+prev2;
        prev2 = prev1;
        prev1 = ans;
    }
    cout << "\nThe number of possible ways to climb " << n << " stairs is : " << ans<< endl;
    return 0;
}