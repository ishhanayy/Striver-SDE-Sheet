//PROBLEM STATMENT : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

//KeyPoint : Using Topological Sorting, if cycle is found then the course cannot get completed according to the given prerequisites, if there is no cycle then we are returning true else false

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n,int p, vector<pair<int, int> >& prerequisites) {
	    //Forming the adjacency list 
	    vector<int> adj[n];
	    for(auto it : prerequisites)
	    {
	        adj[it.first].push_back(it.second);
	    }
	    // if there we find out cycle then the task is not possible
	    vector<int> inDegree(n, 0);
	    for(int i = 0; i<n; i++)
	    {
	        for(auto it : adj[i])
	        {
	            inDegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    //now we will traverse in the inDegree and check if the inDegree is 0 anywhere 
	    for(int i = 0; i<n; i++)
	    {
	        if(inDegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    //now we will find out the toposort
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
	        return true;
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
