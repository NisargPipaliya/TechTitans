#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        int n = floor(nums.size()/3);

        for(int i = 0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }

        for(auto& i : m)
        {
            if(i.second > n)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};