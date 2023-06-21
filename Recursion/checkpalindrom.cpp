/*Check if the string is palindrom or not using recursion*/
#include <iostream>
#include <string>
using namespace std;
bool helper(string s, int l, int r)
{
    if(r<=l)
    {
        return true;
    }
    if(s[l]!=s[r])
    {
        return false;
    }
    else
    {
        return helper(s, l+1, r-1);
    }
}
bool checkPalindrome(string s)
{
    // Write your code here.
    return helper(s, 0, s.size()-1);
}
int main() {
    string s;
    cout<<"Enter the string you want to check if palindrom : ";
    cin>>s;
    cout<<endl;
    bool isPalindrome = checkPalindrome(s);
    if (isPalindrome)
    {
        cout <<"Input is a palindrome."<<endl;
    }
    else
    {
        cout<<"Input is not a palindrome."<<endl;
    }
    return 0;
}