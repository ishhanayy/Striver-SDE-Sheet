//PROBLEM STATEMENT : https://www.interviewbit.com/problems/allocate-books/

int maxi_ele(vector<int>& a)
{
    int maxi = INT_MIN;
    for(int i =0; i<a.size(); i++)
    {
        maxi = max(maxi, a[i]);
    }
    return maxi;
}
int sum_arr(vector<int>& a)
{
    int sum = 0;
    for(int i =0; i<a.size(); i++)
    {
        sum+=a[i];
    }
    return sum;
}
int studentCount(vector<int>& arr, int pages)
{
    int student = 1;
    int pages_stu_have = 0;
    for(int i =0; i<arr.size(); i++)
    {
        if((arr[i]+pages_stu_have)<=pages)
        {
            pages_stu_have+=arr[i];
        }
        else
        {
            pages_stu_have = arr[i];
            student++;
        }
    }
    return student;
}
int Solution::books(vector<int> &a, int b) 
{
    if(a.size()<b)
    {
        return -1;
    }
    int low = maxi_ele(a);
    int high = sum_arr(a);
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        int count_student = studentCount(a, mid); //mid denotes the pages here
        if(count_student>b)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return low;
}
