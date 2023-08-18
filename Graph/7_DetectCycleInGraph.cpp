//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTab=0


//Using BFS(Breath First Searrch)

#include <queue>
#include <vector>
bool detect(int start, vector<int> adj[], vector<int>& visited)
{
    visited[start] = 1;
    queue<pair<int, int>> q; //{node, parent}
    q.push({start, -1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto i : adj[node])
        {
            if(!visited[i])
            {
                visited[i] = 1;
                q.push({i, node});
            }
            else
            {
                if(i!=parent)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edge, int n, int m)
{
    vector<int> adj[n+1];
    for(int i = 0; i<m; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    vector<int> visited(n+1, 0);
    for(int i =1; i<=n; i++)
    {
        if(!visited[i])
        {
            if(detect(i, adj, visited))
            {
                return "Yes";
            }
        }
    }
    return "No";
}


//Using Depth First Search

bool detect(int start, int parent, vector<int> adj[], vector<int>& visited)
{
    visited[start] = 1;
    for(auto i : adj[start])
    {
        if(!visited[i])
        {
            if(detect(i, start, adj, visited))
            {
                return true;   
            }
        }
        else
        {
            if(i!=parent)
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edge, int n, int m) 
{
    vector<int> adj[n+1];
    for(int i = 0; i<m; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    vector<int> visited(n+1, 0);
    for(int i =1; i<=n; i++)
    {
        if(!visited[i])
        {
            if(detect(i, -1, adj, visited))
            {
                return "Yes";
            }
        }
    }
    return "No";   
}
