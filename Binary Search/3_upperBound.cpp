//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTab=1

/*----------------------ITERATIVE---------------------------*/
int upperBound(vector<int> &arr, int tar, int n)
{
	int low =0;
	int high = n-1;
	int ans = n; //atleast the answer will always be hypothetical lower bound, 
	while(low<=high)
	{
		int mid = low+(high-low)/2;
		//we have to find the upper bound, and in the binary search instead of finding the element we are searching for the upper bound index
		if(arr[mid]>tar)
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