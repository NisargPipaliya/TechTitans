#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> genRow(int r)
    {
        long long ans = 1;
        vector<int> list;

        list.push_back(1);

        for(int i = 1; i<r; i++)
        {
            ans = ans * (r-i);
            ans = ans/i;
            list.push_back(ans);
        }
        return list;
    }
    vector<vector<int>> generate(int numRows) {
        int sum = 1;
        vector<vector<int>> ans;
        for(int i = 0; i< numRows; i++)
        {
           ans.push_back(genRow(i+1));
        }
        return ans;
    }
};