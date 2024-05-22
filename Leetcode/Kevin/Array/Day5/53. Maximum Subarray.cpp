//  Link :: https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums[0];
        for(int i=0;i<nums.size();i++){
            if(sum + nums[i] > 0 ){
                sum  += nums[i];
                if(sum > max)
                    max = sum;
            }
            else{
                sum = 0;
                if(nums[i] > max)
                    max = nums[i];
            }
        }

        return max;
    }
};