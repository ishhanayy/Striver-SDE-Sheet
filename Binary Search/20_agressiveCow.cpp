//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/aggressive-cows_1082559?leftPanelTab=1

bool helper(vector<int> &stalls, int dis, int k)
{
    int count_cow = 1;
    int last_cow = stalls[0];
    for(int i = 1; i<stalls.size(); i++)
    {
        if(stalls[i]-last_cow>=dis)
        {
            count_cow++;
            last_cow = stalls[i];
        }
        
        if(count_cow>=k)
        {
            return true;
        }
    }
    return false;
    
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end()); //as the stalls array denotes the position of the stalls, which can be definately sorted
    int low = 1;
    int ans = 0;
    int high = stalls[stalls.size()-1]-stalls[0];
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(helper(stalls, mid, k))
        {
            ans = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return ans;
}