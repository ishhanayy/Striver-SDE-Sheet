/*---------------------------RECURSION-------------------------------------------*/
int helper(int day, vector<vector<int>>& points,int prevTask)
{
    if(day==0)
    {
        int point =0; 
        for(int i =0; i<3; i++)
        {
            if(i!=prevTask)
            {
                point =max(point, points[0][i]);
            }
        }
        return point;
    }
    int maximum = 0;
    for(int i = 0; i<3; i++)
    {
        if(i!=prevTask)
        {
            int point = points[day][i]+helper(day-1, points, i);
            maximum = max(maximum, point);
        }
    }
    return maximum;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int prevTask = 3;//Because Till now we haven't performed any task.
    return helper(n-1, points, prevTask);
}


/*---------------------------MEMOIZATION-------------------------------------------*/
int helper(int day, vector<vector<int>>& points, int prevTask, vector<vector<int>>& dp)
{
    if(day==0)
    {
        int point =0; 
        for(int i =0; i<3; i++)
        {
            if(i!=prevTask)
            {
                point =max(point, points[0][i]);
            }
        }
        return point;
    }
    
    if(dp[day][prevTask]!=-1)
    {
        return dp[day][prevTask];
    }

    int maximum = 0;
    for(int i = 0; i<3; i++)
    {
        if(i!=prevTask)
        {
            int point = points[day][i]+helper(day-1, points, i, dp);
            maximum = max(maximum, point);
        }
    }
    return dp[day][prevTask] = maximum;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int prevTask = 3;//Because Till now we haven't performed any task.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(n-1, points, prevTask, dp);
}