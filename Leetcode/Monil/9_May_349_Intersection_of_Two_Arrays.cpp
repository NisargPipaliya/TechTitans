#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> temp;
        
        for(auto i:nums1)
        {
            if(temp[i]==0)
            {
                temp[i]++;
            }
        }
        vector<int> rs;

        for(auto i:nums2)
        {
            if(temp[i] == 1)
            {
                rs.push_back(i);
                temp[i]--;
            }
        }
        return rs;
    }
};