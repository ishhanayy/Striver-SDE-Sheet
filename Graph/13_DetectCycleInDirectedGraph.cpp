//PROBLEM STATMENT : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool dfs(int start, vector<int> adj[], int visited[], int pathVisited[])
    {
        visited[start] = 1;
        pathVisited[start] = 1;
        for(auto it : adj[start])
        {
            if(!visited[it])
            {
                if(dfs(it, adj, visited, pathVisited)==true)
                {
                    return true;
                }
            }
            else if(pathVisited[it]==1)
            {
                return true;
            }
        }
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        int visited[v] = {0}; //initializing all the elements as zero
        int pathVisited[v] = {0};
        
        for(int i = 0; i<v; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, adj, visited, pathVisited)==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//***********************CODING NINJA****************************

//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=1

bool dfs(int i, vector<int> adj[], vector<int>& vis, vector<int>& pv)
{
  vis[i] = 1;
  pv[i] = 1;
  for(auto it : adj[i])
  {
    //when the node over the adj is not being visited 
    if(vis[it]==0)
    {
      if(dfs(it, adj, vis, pv)==true)
      {
        return true;
      }

    }

    else if(pv[it]==1)
    {
      return true;
    }
  }

  pv[i] = 0;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & grid) 
{
  //we need to make the adjacency list for the edges vector we have been given
  vector<int> adj[n+1];
  for(int i = 0; i<grid.size(); i++)
  {
    adj[grid[i].first].push_back(grid[i].second);
  }  

  //now we required visited for the check that node have been visited or not 
  //and we are required the pathVisited to check whether the following node is in the ongoing path or not
  vector<int> visited(n+1, 0);
  vector<int> pathVisited(n+1, 0);

  for(int i = 1; i<=n; i++)
  {
    if(visited[i]==0)
    {
      //means it have been not visited till now
      if(dfs(i, adj, visited, pathVisited)==true)
      {
        return 1;
      }
    }
  }
  return 0; 
}
