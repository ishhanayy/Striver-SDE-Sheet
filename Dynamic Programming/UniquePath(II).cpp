//PROBLEM STATEMENT : https://www.codingninjas.com/codestudio/problems/unique-paths-ii_977241?leftPanelTab=1

/*---------------------------RECURSION-------------------------------------------*/
int helper(int m, int n, vector<vector<int>>& mat) {
    if (m < 0 || n < 0 || mat[m][n] == -1) {
        return 0;
    }
    if (m == 0 && n == 0) {
        return 1;
    }
    
    int a = helper(m - 1, n, mat);
    int b = helper(m, n - 1, mat);
    
    return a + b;
}

int mazeObstacles(int m, int n, vector<vector<int>>& mat) {
    return helper(m - 1, n - 1, mat);
}


/*---------------------------MEMOIZATION-------------------------------------------*/
int mod = (int)(1e9+7);
int helper(int m, int n, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (m < 0 || n < 0 || mat[m][n] == -1) {
        return 0;
    }
    if (m == 0 && n == 0) {
        return 1;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    int a = helper(m - 1, n, mat, dp);
    int b = helper(m, n - 1, mat, dp);
    
    return dp[m][n] =  (a + b)%mod;
}

int mazeObstacles(int m, int n, vector<vector<int>>& mat) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m - 1, n - 1, mat, dp);
}


/*---------------------------TABULATED-------------------------------------------*/
int mod = (int)(1e9+7);
int mazeObstacles(int m, int n, vector<vector<int>>& mat) 
{
    vector<vector<int>> dp(m,vector<int>(n,0));
    
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
          if (mat[i][j] == -1) 
          {
            dp[i][j] = 0;
          } else if (i == 0 && j == 0) 
          {
            dp[i][j] = 1;
          } else 
          {
            int a = 0;
            int b = 0;

            if (i > 0) 
            {
              a = dp[i - 1][j];
            }

            if (j > 0)
             {
              b = dp[i][j - 1];
            }

            dp[i][j] = (a + b)%mod;
          }
        }
        
    }
    
    return dp[m-1][n-1];
}


/*---------------------------MORE OPTIMIZED-------------------------------------------*/
int mod = (int)(1e9+7);
int mazeObstacles(int m, int n, vector<vector<int>>& mat) {
    vector<int> dp(n, 0);
    
    for (int i = 0; i < m; i++) {
        vector<int> temp(n, 0);
        
        for (int j = 0; j < n; j++) {
            if(mat[i][j]==-1)
            {
                temp[j] = 0;
            }
            else if (i == 0 && j == 0) {
                temp[j] = 1;
            } else {
                int a = 0;
                int b = 0;
                
                if (i > 0) {
                    a = dp[j];
                }
                
                if (j > 0) {
                    b = temp[j-1];
                }
                
                temp[j] = (a + b)%mod;
            }
        }
        
        dp = temp;
    }
    
    return dp[n-1];
}
