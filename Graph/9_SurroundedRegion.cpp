//PROBLEM STATEMENT : https://leetcode.com/problems/surrounded-regions/description/

class Solution {
private:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<char>>& ans)
    {
        int m = board.size();
        int n = board[0].size();
        ans[r][c] = 'O';
        for(int i = -1; i<=1; i++)
        {
            for(int j = -1; j<=1; j++)
            {
                if(abs(i)!=abs(j))
                {
                    int new_row = r+i;
                    int new_col = c+j;
                    if(new_row>=0 && new_row<m && new_col>=0 && new_col<n && board[new_row][new_col]=='O' && ans[new_row][new_col]=='$')
                    {
                        dfs(new_row, new_col, board, ans);
                    }
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '$'));
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i==0 || j==0 || i==m-1 || j==n-1)
                {
                    //then the grid position is at the boundary
                    if(board[i][j]=='O' && ans[i][j]!='O')
                    {
                        dfs(i, j, board, ans);
                    }
                }
            }
        }   

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(ans[i][j]=='$')
                {
                    ans[i][j] = 'X';
                }
            }
        } 

        board = ans;
    }
};