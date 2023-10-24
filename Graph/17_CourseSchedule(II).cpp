//PROBLEM STATEMENT : https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User functd a ordering of tasks you should pick to finish all tasion Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //need to make the adjacency list 
        //note that here the direction of the task have been reversed
        //so the adjacency list will be formed considering the reverse order and arranging it into the correct format
        vector<int> adj[n];
        for(int i = 0; i< m; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
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
        for(int i = 0; i< n; i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int> topoSort;
        while(!q.empty())
        {
            int node = q.front();
            topoSort.push_back(node);
            q.pop();
            for(auto it : adj[node])
            {
                inDegree[it]--;
                if(inDegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        
        if(topoSort.size()==n)
        {
            return topoSort;
        }
        
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
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
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends