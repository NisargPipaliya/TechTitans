#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        vector<int> ans;
        for(int i = 0; i<nums.size();i++)
        {
            if(nums[i] == target)
            {
                if(first == -1)
                {
                    first = i;
                }
                if(last<i)
                {
                    last = i;
                }
            }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};