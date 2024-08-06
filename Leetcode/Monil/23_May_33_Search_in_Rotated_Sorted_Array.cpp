
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int low = 0;
        int high = nums.size()-1;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(nums[mid]==target)
            {
                index = mid;
                return index;
            }
            if(nums[low]<=nums[mid])
            {
                if(nums[mid]>=target && nums[low]<=target)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else 
            {
                if(nums[mid]<=target && nums[high]>= target)
                {
                    low = mid + 1;
                }
                else 
                {
                    high = mid - 1;
                }
            }
        }
        return index;
    }
};