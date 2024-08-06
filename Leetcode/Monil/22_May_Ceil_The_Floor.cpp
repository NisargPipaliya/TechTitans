#include <bits/stdc++.h>

using namespace std;
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int low = 0;
	int high = n - 1;
	pair<int,int> ans;

	while(low<=high)
	{
		int mid = (low+high)/2;

		if(a[mid]==x)
		{
			ans.first = x;
			ans.second = x;
			return ans;
		}
		if(a[mid]>x)
		{
			high = mid -1;
		}
		else
		{
			low = mid + 1;
		}
	}
	if(low>0)
	{
		ans.first = a[low -1];
	}
	else{
		ans.first = low - 1;
	}
	if(high == n -1)
	{
		ans.second = -1;
	}
	else{
		ans.second = a[high+1];
	}
	return ans;
}