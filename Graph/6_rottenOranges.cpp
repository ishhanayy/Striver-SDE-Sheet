//PROBLEM STATEMENT : https://leetcode.com/problems/rotting-oranges/

//Using BFS, because we want to return the minimum time

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();   
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j< m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        } 

        int time = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for(int i = -1; i<=1; i++)
            {
                for(int j = -1; j<=1; j++)
                {
                    if(abs(i)!=abs(j))
                    {
                        int new_row = r+i;
                        int new_col = c+j;
                        if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && visited[new_row][new_col]!=2 && grid[new_row][new_col]==1)
                        {
                            //the orange is fresh and not being rotten(not visited)
                            q.push({{new_row, new_col}, t+1});
                            visited[new_row][new_col]=2;
                        }
                    }
                }
            }
        }

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 1 && visited[i][j]!=2)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};