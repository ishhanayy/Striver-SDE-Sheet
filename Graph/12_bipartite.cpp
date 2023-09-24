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

//**************************************************************************************

//PROBLEM STATMENT : https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool check(int start, int v, vector<int> adj[], vector<int>& colour)
    {
        queue<int> q;
	    q.push(start);
	    colour[start] = 0;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        for(auto it : adj[node])
	        {
	            if(colour[it]==-1)
	            {
	                q.push(it);
	                colour[it] = !colour[node];
	            }
	            else if(colour[it]==colour[node])
	            {
	                return false;
	            }
	        }
	    }
	    
	    return true;
    }
public:
	bool isBipartite(int v, vector<int>adj[]){
	    vector<int> colour(v, -1);
	    //we will take 0 and 1 as the color 
	    for(int i = 0; i<v; i++)
	    {
	        if(colour[i]==-1)
	        {
	            if(check(i, v, adj, colour)==false)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	}
	

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
