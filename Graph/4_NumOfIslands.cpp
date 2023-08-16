//PROBLEM STATEMENT : https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int delta_row = -1; delta_row<=1; delta_row++)
            {
                for(int delta_col = -1; delta_col<=1; delta_col++)
                {
                    if(abs(delta_row) != abs(delta_col))
                    {
                        int new_row = r + delta_row;
                        int new_col = c + delta_col;
                        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == '1' && !visited[new_row][new_col])
                        {
                            visited[new_row][new_col] = 1;
                            q.push({new_row, new_col});
                        }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = (grid[0]).size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;
        for(int i =0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    count+=1;
                    bfs(i, j, grid, visited);
                }
            }
        }  
        return count;  
    }
};