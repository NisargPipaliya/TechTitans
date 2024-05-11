//  Link :: https://leetcode.com/problems/rearrange-array-elements-by-sign/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int pos = 0, neg = 1;
        for(int n : nums){
            if(n>= 0){
                ans[pos] = n;
                pos += 2;
            }else{
                ans[neg] = n;
                neg+=2;
            }
        }
        return ans;
    }
};