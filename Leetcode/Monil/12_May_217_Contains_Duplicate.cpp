#include <vector>           
#include <unordered_map>    
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> ans;
        for(int i=0; i<nums.size();i++)
        {
            if(ans[nums[i]] == 1)
            {
                return true;
            }
            ans[nums[i]] = 1;
        }
        return false;
    }
};