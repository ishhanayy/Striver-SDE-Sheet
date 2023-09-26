//PROBLEM STATEMENT : https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool dfs(int i, vector<int> adj[], vector<int>& visited, vector<int>& pv, vector<int>& check)
    {
        visited[i] = 1;
        pv[i] = 1;
        check[i] = 0;
        for(auto it : adj[i])
        {
            if(visited[it]==0)
            {
                if(dfs(it, adj, visited, pv, check)==true)
                {
                    check[it] = 0;
                    return true;
                }
            }
            
            else if(pv[it]==1)
            {
                check[it] = 0;
                return true;
            }
        }
        check[i] = 1;
        pv[i] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int> visited(v, 0);
        vector<int> pathVisited(v, 0);
        vector<int> check(v, 0);
        for(int i = 0; i<v; i++)
        {
            if(visited[i]==0)
            {
                dfs(i, adj, visited, pathVisited, check);
            }
        }
        vector<int> safeNode;
        for(int i =0; i<check.size(); i++)
        {
            if(check[i]==1)
            {
                safeNode.push_back(i);
            }
        }
        
        return safeNode;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends