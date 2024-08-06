class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0, n = nums.size();
        for(int i = 0; i <= maxIndex && i < n; i++){
            maxIndex = max(maxIndex,i + nums[i]);
            if(maxIndex >= n-1)
                return true;
        }
        return false;
    }
};