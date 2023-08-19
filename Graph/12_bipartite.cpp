//PROBLEM STATEMENT : https://leetcode.com/problems/is-graph-bipartite/

//Will be doing it using bfs

class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& colour) 
    {
        //graph is the adjaceny list 
        queue<int> q;
        q.push(start);
        colour[start] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto i : graph[node])
            {
                if(colour[i]==-1)
                {
                    //it means that no have reached it yet
                    colour[i] = !colour[node];
                    q.push(i);
                }
                else  if(colour[i]==colour[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> colour(n, -1);
        for(int i = 0; i<n; i++)
        {
            if(colour[i]==-1)
            {
                if(bfs(i, graph, colour)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};