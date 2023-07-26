//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/lower-bound_8165382?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

/*----------------------ITERATIVE---------------------------*/
int lowerBound(vector<int> arr, int n, int tar) 
{
	int low =0;
	int high = n-1;
	int ans = n; //atleast the answer will always be hypothetical lower bound, 
	while(low<=high)
	{
		int mid = low+(high-low)/2;
		//we have to find the lower bound, and in the binary search instead of finding the element we are searching for the linear bound index
		if(arr[mid]>=tar)
		{
			high = mid-1;
			ans = mid; // we have to find the index of the lower bound
		}
		else
		{
			low = mid+1;
		}
	}
	return ans;
}
