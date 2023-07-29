//PROBLEM STATEMENT : https://www.codingninjas.com/studio/problems/rose-garden_2248080?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTab=1

int min_maxi_bloom(vector<int>& arr, int flag)
{
	int maxi = INT_MIN;
	int mini = INT_MAX;
	for(int i =0; i<arr.size(); i++)
	{
		maxi = max(maxi, arr[i]);
		mini = min(mini, arr[i]);
	}
	if(flag==0)
	{
		return mini;
	}
	else
	{
		return maxi;
	}
}
bool favourable_bouquets(vector<int> arr,int day, int k, int m)
{
	int count = 0;
	int num_bouq = 0;
	for(int i =0; i<arr.size(); i++)
	{
		if(arr[i]<=day)
		{
			//then the flower is bloomed
			count+=1; //we can form a bouquet out of it.
		}
		else
		{
			num_bouq+=count/k; //where k is the number of flower in one bouquet
			count = 0;
		}
	}
	num_bouq+=count/k;
	if(num_bouq>=m) //m is minimum required bouquets
	{
		return true;
	}
	else
	{
		return false;
	}
}
int roseGarden(vector<int> arr, int k, int m)
{
	int low = min_maxi_bloom(arr, 0);
	int high = min_maxi_bloom(arr, 1);
	int ans = -1;
	while(low<=high)
	{
		int mid = low+(high-low)/2;
		bool possible =  favourable_bouquets(arr, mid, k, m);
		if(possible)
		{
			ans = mid;
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	return ans;
}