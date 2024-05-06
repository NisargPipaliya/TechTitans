#include <vector>
using namespace std;
class Solution {
    int bSearch(vector<int> &nums, int target, int l, int h){
        if(l > h)
            return -1;
        int mid = (l+h)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            h = mid - 1;
        else
            l = mid + 1;
        return bSearch(nums,target,l,h);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int index = bSearch(nums,target,0,nums.size()-1);
        if(index == -1)
            return {-1,-1};

        vector<int> ans;
        while(index >= 0 && nums[index] == target)
            index--;
        
        ans.emplace_back(++index);

        while(index < nums.size() && nums[index] == target)
            index++;

        ans.emplace_back(--index);

        return ans;
    }
};