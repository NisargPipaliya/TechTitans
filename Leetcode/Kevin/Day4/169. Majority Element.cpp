//  Link :: https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = nums[0];
        for(int n : nums){
            if(element == n){
                count ++;
            }
            else{
                count--;
                if(count < 0){
                    element = n;
                    count = 1;
                }
            }
        }

        return element;
    }
};