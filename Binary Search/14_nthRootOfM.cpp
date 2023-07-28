//PROBLEM STATMENT : https://www.codingninjas.com/studio/problems/nth-root-of-m_1062679?leftPanelTab=1

/*--------------1st Approach-----------*/
int NthRoot(int n, int m) {
  int low = 1; 
  int high = m;
  while(low<=high)
  {
    int mid = low+(high-low)/2;
    if(pow(mid,n)==m)
    {
      return mid;
    }
    else if(pow(mid, n)>m)
    {
      high = mid-1;
    }
    else
    {
      low = mid+1;
    }
  }
  return -1;
}


/*--------------2nd Approach-----------*/
int func(int mid, int n, int m)
{
  long long ans = 1;
  for(int i =1; i<=n; i++)
  {
    ans*=mid;
    if(ans>m){return 2;}
  }
  if(ans==m){return 1;}
  return 0;
}
int NthRoot(int n, int m) {
  int low = 1;
  int high = m;
  while(low<=high)
  {
    int mid = low+(high-low)/2;
    int mid_n = func(mid, n, m);
    if(mid_n==1)
    {
      return mid;
    }
    else if(mid_n==0)
    {
      low = mid+1;
    }
    else
    {
      high = mid-1;
    }
  }
  return -1;
}