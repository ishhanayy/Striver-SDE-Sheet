//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/dfs-traversal_630462?leftPanelTab=1

#include <vector>

void helper(int start, vector<int> adj[], vector<int>& dfs, vector<int>& visited)
{
    visited[start] = 1;
    dfs.push_back(start);
    for(auto it : adj[start])
    {
        if(!visited[it])
        {
            helper(it, adj, dfs, visited);
        }
    }
}
vector<vector<int>> depthFirstSearch(int n, int m, vector<vector<int>> &edges)
{
    vector<int> adj[n]; // if n = 5 then the node are 0, 1, 2, 3 ,4 (starting from zero)
    for(int i = 0; i<m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);

    }
    vector<vector<int>> ans;
    vector<int> visited(n, 0);
    for(int i =0; i<n; i++)
    {
        if(!visited[i])
        {
            vector<int> dfs;
            helper(i, adj, dfs, visited);
            ans.push_back(dfs);
        }
    }
    return ans;
}