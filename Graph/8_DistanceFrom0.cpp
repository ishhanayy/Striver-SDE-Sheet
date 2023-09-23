//PROBLEM STATEMENT : https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        //we will put all the zeros in the queue
        //we will use the bfs we want to find the distance of zero from every grid 
        queue<pair<pair<int, int>, int>> q;
        int m = mat.size(); //number of rows 
        int n = mat[0].size();  //number of coloumn
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for(int i =0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(mat[i][j]==0)
                {
                    ans[i][j] = 0;
                    q.push({{i, j}, 0}); //number of step to reach from 0 to 0 is 0
                }
            }
        }

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            for(int i = -1; i<=1; i++)
            {
                for(int j = -1; j<=1; j++)
                {
                    if(abs(i)!=abs(j))
                    {
                        int new_r = r+i;
                        int new_c  = c+j;
                        if(new_r>=0 && new_r<m && new_c>=0 && new_c<n && ans[new_r][new_c]==-1)
                        {
                            ans[new_r][new_c] = step+1;
                            q.push({{new_r, new_c}, step+1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//***************************************************************************************************************
//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/distance-of-nearest-cell-having-1-in-a-binary-matrix_1169913?leftPanelTab=1

vector<vector<int>> nearest(vector<vector<int>> &mat, int n, int m) {
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> res(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                vis[i][j] = 1;
                q.push({{i, j}, 0});
            }
        }
    }

    // Define the possible directions: up, down, left, right
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;
        q.pop();

        res[row][col] = step;

        for (int d = 0; d < 4; d++) {
            int nrow = row + dir[d][0];
            int ncol = col + dir[d][1];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, step + 1});
            }
        }
    }

    return res;
}
