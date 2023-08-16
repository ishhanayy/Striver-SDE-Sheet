///PROBLEM STATEMENT : https://leetcode.com/problems/flood-fill/

//Will apply the DFS via recursion

class Solution {
private:
    void dfs(int sr, int sc, int initial_colour, int new_colour, vector<vector<int>>& ans, vector<vector<int>>& image)
    {
        ans[sr][sc] = new_colour;
        int n = ans.size();
        int m = ans[0].size();
        for(int i = -1; i<=1; i++)
        {
            for(int j = -1; j<=1; j++)
            {
                if(abs(i)!=abs(j))
                {
                    int new_row = sr+i;
                    int new_col = sc+j;
                    if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && image[new_row][new_col]==initial_colour && ans[new_row][new_col]!=new_colour)
                    {
                        dfs(new_row, new_col, initial_colour, new_colour, ans, image);
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int initial_colour = image[sr][sc]; //sr and sc is the starting row and starting coloumn from where and which pixel point we have to alter the colour with the new colour
        vector<vector<int>> ans = image; // we dont want to alter the original data, so the new image will be stored as the ans
        dfs(sr, sc, initial_colour, color, ans, image);    
        return ans;
    }
};