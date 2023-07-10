//PROBLEM STATEMENT : https://leetcode.com/problems/shortest-common-supersequence/

/*-------------------------------------USED TABULATION-------------------------------------------*/
class Solution {
public:
    string shortestCommonSupersequence(string s, string t) 
    {
        vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
        for(int i = 0; i<=s.size(); i++)
        {
            dp[i][0] = 0;
        }  
        for(int j = 0; j<=t.size(); j++)
        {
            dp[0][j] = 0;
        }
        for(int i = 1; i<=s.size(); i++)
        {
            for(int j = 1; j<=t.size(); j++)
            {
                if(s[i-1]==t[j-1]) //the strings considered to be 0-indexed string.
                {
                    dp[i][j] = 1+dp[i-1][j-1];  // if any two current character will match then we will move i and j pointer both in forward , otherwise we will get duplicated in answer
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans = "";
        int i = s.size();
        int j = t.size();
        while(i>0 && j>0)
        {
            if(s[i-1] == t[j-1])
            {
                ans += s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]<dp[i][j-1])
            {
                ans += t[j-1];
                j--;
            }
            else
            {
                ans += s[i-1];
                i--;
            }
        }
        while(i>0)
        {
            ans+=s[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=t[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};