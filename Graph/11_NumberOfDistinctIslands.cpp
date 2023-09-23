//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/distinct-islands_630460?leftPanelTab=0

#include <vector>
#include <set>
#include <utility> 

void dfs(int r, int c, int** arr, int n, int m,  std::vector<std::vector<int>>& visited, std::vector<std::pair<int, int>>& store, int& baseR, int& baseC)
{
    visited[r][c] = 1;
    store.push_back({r-baseR, c-baseC});
    for(int i = -1; i<=1; i++)
    {
        for(int j = -1; j<=1; j++)
        {
            if(abs(i)!=abs(j))
            {
                int new_r = r+i;
                int new_c = c+j;
                if(new_r>=0 && new_r<n && new_c>=0 && new_c<m && arr[new_r][new_c]==1 && !visited[new_r][new_c])
                {
                    dfs(new_r, new_c, arr, n, m, visited, store, baseR, baseC);
                }
            }
        }
    }
}

int distinctIslands(int** arr, int n, int m) //n is the row and m is the coloumn
{
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> s;
    int count = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(arr[i][j]==1 && visited[i][j]==0)
            {
                vector<pair<int, int>> store;
                dfs(i, j, arr, n, m, visited, store, i, j);
                s.insert(store);
            }
        }
    }
    return s.size();
}

//**********************************************************************************************************

//PROBLEM STATEMENT =>
//GFG : https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, set<list<pair<int, int>>>& store)
    {
        list<pair<int, int>> temp;
        temp.push_back({0, 0}); // Start with the relative position (0, 0) for the initial cell.
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        queue<pair<int, int>> q;
        q.push({i, j});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int nrow = dr[k] + row;
                int ncol = dc[k] + col;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    // Calculate relative position with respect to the starting cell (i, j).
                    temp.push_back({nrow - i, ncol - j});
                }
            }
        }
        store.insert(temp);
    }


  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        set<list<pair<int, int>>> store;
        for(int i = 0;i < n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    bfs(i, j, grid, visited, store);
                }
            }
        }
        return store.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
