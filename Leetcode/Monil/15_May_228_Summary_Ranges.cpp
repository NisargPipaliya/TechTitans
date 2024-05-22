#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if(n==0)
        {
            return ans;
        }
        int val = nums[0];
        int flag = 0;
        
        string s = "";
        s.append(to_string(nums[0]));

        for(int i = 1; i<n; i++ )
        {
            if(nums[i]!=val+1)
            {
                if(flag)
                {
                    s.append("->");
                    s.append(to_string(nums[i-1]));
                    flag=0;
                }
                ans.push_back(s);
                s="";
                //val = nums[i];
                s.append(to_string(nums[i]));
            }else{
                flag = 1;
            }
            val = nums[i];
        }
        if(flag)
        {
            s.append("->");
            s.append(to_string(nums[n-1]));
        }
        ans.push_back(s);
        return ans;
    }
};