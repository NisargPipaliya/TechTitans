# Link : https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int start = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] !=1){
                if(i-start > count)
                    count = i-start;
                start =  i+1; 
            }
        }
         if(nums.size()-start > count)
            count = nums.size()-start;
        return count;
    }
};