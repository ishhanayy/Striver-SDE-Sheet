//PROBLEM STATEMENT : https://leetcode.com/problems/number-of-enclaves/description/

class Solution {
private: 
    void dfs(int r, int c, vector<vector<int>>& grid, int& count, vector<vector<int>>& visited)
    {
        int m = grid.size();
        int n = grid[0].size();
        count++;
        visited[r][c] = 1;
        for(int i = -1; i<=1; i++)
        {
            for(int j = -1; j<=1; j++)
            {
                if(abs(i)!=abs(j))
                {
                    int new_row = r+i; 
                    int new_col = c+j;
                    if(new_row>=0 && new_row<m && new_col>=0 && new_col<n && grid[new_row][new_col]==1 && !visited[new_row][new_col])
                    {
                        dfs(new_row, new_col, grid, count, visited);
                    }
                }
            }
        }
        return;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int boundary_one = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i==0 || j==0 || i==m-1 ||j ==n-1)
                {
                    if(grid[i][j]==1 && !visited[i][j])
                    {
                        dfs(i, j, grid, boundary_one, visited);
                    }
                }
            }
        }   

        int total_one = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    total_one++;
                }
            }
        } 

        return total_one-boundary_one;
    }
};

//*******************************************************************************************
//PROBLEM STATMENT : https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); // Number of rows
        int m = grid[0].size(); // Number of columns
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Visit the boundary land and mark it as visited
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if (grid[i][m - 1] == 1) {
                q.push({i, m - 1});
                visited[i][m - 1] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1) {
                q.push({0, i});
                visited[0][i] = 1;
            }
            if (grid[n - 1][i] == 1) {
                q.push({n - 1, i});
                visited[n - 1][i] = 1;
            }
        }

        // Perform BFS to mark all connected land
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int k = 0; k < 4; k++) {
                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        // Count the unvisited land
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends
