// Link :: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for(int i =0; i< n ;i++){
            for(int j = i+1; j < n;  j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                
            }
        }
        return ans;
    }
};