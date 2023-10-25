//BOTH DFS AND BFS SOLUTION ADDED (SCROLL DOWN) 

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

//PROBLEM STATEMENT : https://leetcode.com/problems/find-eventual-safe-states/

//Using DFS

class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVisited, vector<int>& check)
    {
        visited[i] = 1;
        pathVisited[i] = 1;
        check[i] = 0;
        for(auto it : graph[i])
        {
            if(visited[it]==0)
            {
                if(dfs(it, graph, visited, pathVisited, check)==true)
                {
                    check[it] = 0;
                    return true;
                }
            }
            else if(pathVisited[it]==1)
            {
                check[it] = 0;
                return true;
            }
        }
        check[i] = 1;
        pathVisited[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //We have been given an adjacency list 
        //We will create the visited list to keep the track of all the visited node while traversing 
        //We will create the PathVisited list to keep the track if there is any cycle in the path 
        //We will maintain a check list to keep the track of all the node which don't have cycle in the path.
        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> pathVisited(n, 0);
        vector<int> check(n, 0);
        for(int i =0; i<n; i++)
        {
            if(visited[i]==0)
            {
                dfs(i, graph, visited, pathVisited, check);
            }
        }

        //we will create SafeNode list to store all the safe nodes;
        vector<int> safeNode;
        for(int i = 0; i<check.size(); i++)
        {
            if(check[i]==1)
            {
                safeNode.push_back(i);
            }
        }

        return safeNode;
    }
};


//Using BFS ( Kahns Algorithm )
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        //Firstly we will make the adjacency list but storing it as reversed graph   
        vector<int> adj[n];
        for(int i = 0; i<n; i++)
        {
            for(auto it : graph[i])
            {
                adj[it].push_back(i);
            }
        }  

        
        vector<int> inDegree(n, 0);
        for(int i = 0; i<n; i++)
        {
            for(auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i<n; i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int> safeNode;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNode.push_back(node);
            for(auto it : adj[node])
            {
                inDegree[it]--;
                if(inDegree[it]==0)
                {
                    q.push(it);
                }
            }
        }

        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};
