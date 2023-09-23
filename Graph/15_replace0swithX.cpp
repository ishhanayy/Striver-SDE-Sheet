//PROBLEM STATMENT : https://www.codingninjas.com/studio/problems/replace-o-with-x_630517?leftPanelTab=1

#include <vector>

void dfs(int row, int col, vector<vector<int>>& vis, char** arr, int delrow[], int delcol[], int n, int m)
{
    vis[row][col] = 1;

    for(int i = 0; i<4; i++)
    {
        int new_row = row+delrow[i];
        int new_col = col+delcol[i];
        if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && vis[new_row][new_col]==0 && arr[new_row][new_col]=='O')
        {
            dfs(new_row, new_col, vis, arr, delrow, delcol, n, m);
        }
    }
}
void replaceOWithX(char** arr, int n, int  m)
{
    //Write your code here  
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0));

    //checking on the first row and last row for the O's
    for(int i = 0; i<m; i++)
    {
        if(vis[0][i]==0 && arr[0][i]=='O')
        {
            dfs(0, i, vis, arr, delrow, delcol, n, m);
        }

        if(vis[n-1][i]==0 && arr[n-1][i]=='O')
        {
            dfs(n-1, i, vis, arr, delrow, delcol, n, m);
        }
    }

    //checking on the first coloumn and the last coloumn for the O's

    for(int i = 0; i<n; i++)
    {
        if(vis[i][0]==0 && arr[i][0]=='O')
        {
            dfs(i, 0, vis, arr, delrow, delcol, n, m);
        }

        if(vis[i][m-1]==0 && arr[i][m-1]=='O')
        {
            dfs(i, m-1, vis, arr, delrow, delcol, n, m);
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(!vis[i][j] && arr[i][j]=='O')
            {
                arr[i][j] = 'X';
            }
        }
    }
}