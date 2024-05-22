// Link : https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> a(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            a[nums[i]] = 1;
        }
        for(int i=0;i<a.size();i++){
            if(!a[i] )
                return i;
        }
        return 0;
    }
};