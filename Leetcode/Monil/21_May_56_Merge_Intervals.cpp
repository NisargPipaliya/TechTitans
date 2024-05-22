#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        for(int i = 1; i<intervals.size();i++)
        {
            if(temp[1]>=intervals[i][0])
            {
                if(temp[1]<intervals[i][1])
                {
                    temp[1]=intervals[i][1];
                }
            }
            else
            {
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};