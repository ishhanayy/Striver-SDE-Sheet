//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401

int helper_floor(int arr[], int n, int tar) 
{
	int low = 0;
	int high = n-1;
	int ans = -1;
	while(low<=high)
	{
		int mid = low+(high-low)/2;
		if(arr[mid]<=tar)
		{
			ans = arr[mid];
			low = mid+1; //becuase we need to find the largest element which is smaller than or equal to target
		}
		else
		{
			high = mid-1;
		}
	}
	return ans;
}
int helper_ceil(int arr[], int n, int tar) 
{
	int low = 0;
	int high = n-1;
	int ans = -1;
	while(low<=high)
	{
		int mid = low+(high-low)/2;
		if(arr[mid]>=tar)
		{
			ans = arr[mid];
			high = mid-1; //becuase we need to find the largest element which is smaller than or equal to target
		}
		else
		{
			low = mid+1;
		}
	}
	return ans;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int tar) 
{
	pair<int, int> p;
	sort(arr, arr+n); 
	p.first = helper_floor(arr, n, tar);
	p.second = helper_ceil(arr, n, tar);
	return p;
}
