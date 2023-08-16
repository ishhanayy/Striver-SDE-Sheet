//PROBLEM STATEMENT : https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void dfs(int start, vector<vector<int>>& isConnected, vector<int>& visited)
    {
        visited[start] = 1;
        for(int it = 0; it<isConnected.size(); it++)
        {
            if(!visited[it] && it!=start && isConnected[start][it])
            {
                dfs(it, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        vector<int> visited(isConnected.size(), 0);
        int count = 0;
        for(int i =0; i<visited.size(); i++)
        {
            if(visited[i]==0)
            {
                count++;
                dfs(i, isConnected, visited);
            }
            else
            {
                continue;
            }
        }
        return count;
    }
};