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