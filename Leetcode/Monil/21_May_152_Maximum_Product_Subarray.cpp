#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = nums[0];
        long long sum = 1;
        
        for(int i = 0;i<nums.size();i++)
        {
            
            sum = sum * (nums[i]);

            if(sum > max)
            {
                max = sum;
            }
            if(sum == 0)
            {
                sum = 1;
            }
        }
        sum = 1;
        for(int i = nums.size()-1;i>=0;i--)
        {
            
            sum = sum * (nums[i]);

            if(sum > max)
            {
                max = sum;
            }
            if(sum == 0)
            {
                sum = 1;
            }
        }
        return max;
    }
};