#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int final = nums[0];

        // for(int i = 0; i< nums.size(); i++)
        // {
        //     for(int j = i; j < nums.size();j++)
        //     {
        //         sum += nums[j];
                
        //         if(sum > final)
        //         {
        //             final = sum;
        //         }
        //     }
        //     sum= 0;
        // }

        for(int i = 0; i< nums.size(); i++)
        {
            sum += nums[i];
            if(final < sum)
            {
                final = sum;
            }
            if(sum < 0)
            {
                sum = 0;
            }
        }
        return final;
    }
};