// Link :: https://leetcode.com/problems/next-permutation/
// Edge case should be important to consider. like [1,2,3] or [3,2,1] or [1,1,5] or [1,1,1]
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=  nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i] <= nums[i-1])
                continue;
            else{
                reverse(nums, i, n-1);
                int j = i;
                while(nums[j] <= nums[i-1])
                    j++;
                int temp = nums[j];
                nums[j] = nums[i-1];
                nums[i-1] = temp;
                return ;
            }
        }
        reverse(nums,0,n-1);
    }

    void reverse(vector<int>& nums, int s, int e){
        for(int i = s; i<=s + (e-s)/2 ; i++){
             int temp = nums[i];
                nums[i] = nums[e+s-i];
                nums[e+s-i] = temp;
        }
    }
};