#include<vector>
#include <map> 
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        map<int,int> temp ;
        int n = nums.size();
        for(int j = 0;j<n;j++)
        {
            for(auto i:nums[j])
            {
                temp[i]++;
            }
        }

        vector<int> ans;

        for(auto i: nums[n-1])
        {
            if(temp[i]==n)
            {
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};