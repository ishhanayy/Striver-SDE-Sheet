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