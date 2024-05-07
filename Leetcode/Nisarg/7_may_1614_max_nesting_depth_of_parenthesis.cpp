#include<string>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int ans = INT_MIN,tans = 0, n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(')
                tans++;
            if(s[i] == ')')
                tans--;
            ans = max(ans,tans);
        }
        return ans;
    }
};