//PROBLEM STATMENT : https://www.codingninjas.com/studio/problems/bfs-in-graph_973002?leftPanelTab=1

#include <queue>

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> visited(n, 0); // it will keep the track that if the node is visited or not.
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        bfs.push_back(temp);
        for(auto it : adj[temp])
        {
            if(!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}