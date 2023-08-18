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