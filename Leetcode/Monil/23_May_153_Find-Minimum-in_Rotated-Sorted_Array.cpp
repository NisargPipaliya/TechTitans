
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
     int low = 0;
     int min = INT_MAX;
     int high = nums.size() -1;

     while(low <= high)
     {
        int mid = (low + high)/2;
        if(min>nums[mid])
        {
            min = nums[mid];
        }

        if(nums[mid]>=nums[low])
        {
            if(nums[mid]<nums[high])
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else
        {
            high = mid - 1;
        }
     }
    //  if(min > nums[low])
    //  {
    //     min = nums[low];
    //  }
     return min;   
    }
};