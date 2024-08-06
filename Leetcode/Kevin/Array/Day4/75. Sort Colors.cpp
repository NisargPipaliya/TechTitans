// Link :: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> check(3, 0);
        for(int n : nums){
            check[n]++;
        }
        int x = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<check[i];j++){
                nums[j+x] = i;
            }
            x += check[i];
        }
    }
};