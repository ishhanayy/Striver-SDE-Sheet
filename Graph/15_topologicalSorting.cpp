// Topological Sorting : 

// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.

// It is only possible i the DAG because if we are having cycle in the graph then it won't be possible to have a vertice before the other because they are forming cycle.

// it is directed also for the same reason , because in undirected there is edge from both the side and that is why it is not possible in topological sorting.

// Intution : So the intution is very clear that for the topological sorting we will traverse over the adjacency list and mark them visited by maintaing a visited vector and a stack which will store the sorted sequence. 


//PROBLEM STATEMENT : https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int i, vector<int> adj[], vector<int>& visited, stack<int>& s)
    {
        visited[i] = 1;
        for(auto it : adj[i])
        {
            if(visited[it]==0)
            {
                dfs(it, adj, visited, s);
            }
        }
        s.push(i);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    vector<int> visited(v, 0);
	    vector<int> ans;
	    stack<int> s;
	    for(int i = 0; i<v; i++)
	    {
	        if(visited[i]==0)
	        {
	            dfs(i, adj, visited, s);
	        }
	    }
	    
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
	
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends