/*Print your name N times using Recursion*/
#include <iostream>
#include <string>
using namespace std;
void helper(int n, string name)
{
    if(n==0)
    {
        return;
    }
    cout<<name<<endl;
    helper(n-1, name);
}
int main() {
    int n; //n times the name will be printed
    cout<<"Enter the Num of times you want to print your name:";
    cin>>n;
    cout<<"\n";
    string name ;
    cout<<"Now Enter Your name : ";
    cin>>name;
    cout<<"\n";
    helper(n, name);
    return 0;
}


/*Print linearly from n to 1 using Recursion*/
#include <iostream>
using namespace std;
void helper(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";
    helper(n-1);
    cout<<endl;
}
int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<"\n";
    helper(n);
    return 0;
}


/*Print linearly from 1 to n using Recursion*/
#include <iostream>
using namespace std;
void helper(int n, int i)
{
    if(i>n)
    {
        return;
    }
    cout<<i<<" "; //Note that the print line is above the recursion call
    helper(n, i+1);
    cout<<endl;
}
int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<"\n";
    helper(n, 1);
    return 0;
}


/*Print linearly from n to 1 using BackTracking*/
#include <iostream>
using namespace std;
void helper(int n, int i)
{
    if(i>n)
    {
        return;
    }
    helper(n, i+1);
    cout<<i<<" "; //Note that the print line is below the recursion call
    cout<<endl;
}
int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<"\n";
    helper(n, 1);
    return 0;
}


/*Print linearly from 1 to n using BackTracking*/
#include <iostream>
using namespace std;
void helper(int n)
{
    if(n==0)
    {
        return;
    }
    helper(n-1);
    cout<<n<<" ";
    cout<<endl;
}
int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<"\n";
    helper(n);
    return 0;
}
