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
