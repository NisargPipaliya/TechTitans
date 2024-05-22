//  Link:  :: https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(1,0);
        int s=0;
        int count = 0;
        for(int i : nums){
            s+= i;
            sum.push_back(s);
        }   
        for(int i=0;i<n+1;i++){
            for(int j=i+1;j<n+1;j++){
                if(sum[j] - sum[i] == k){
                    count++;
                }
            }
        }
        return count;
    }
};