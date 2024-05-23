
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high)
        {
            int mid = (low+high)/2;

            if(nums[mid]==target)
            {
                return true;
            }

            if(nums[mid]>target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        } 
        return false;
    }
};