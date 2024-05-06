#include<vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int cnt = 0;

        for(int i = 0; i< nums.size(); i++)
        {
            int j = i;
            
            while(j<nums.size())
            {
                sum+=nums[j];
                if(sum == k)
                {
                    cnt++;
                }
                j++;
            }
            sum = 0;
        }
        return cnt;
    }
};