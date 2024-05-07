#include<vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        int p=0,n=1;
        vector<int> ans(size, 0);

        for(int i = 0; i < size; i++)
        {
            if(nums[i]>0)
            {
                ans[p] = nums[i];
                p+=2;
            }
            else
            {
                ans[n] = nums[i];
                n+=2;
            }
        }
        return ans;
    }
};