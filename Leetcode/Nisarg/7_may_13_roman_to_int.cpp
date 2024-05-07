#include<map>
#include<string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0, n = s.size();
        int i ;
        for(i = 0; i < n - 1; i++){
            int x = m[s[i]];
            if(m[s[i+1]] > x){
                x = m[s[i+1]] - x;
                i++;
            }
            ans += x;
        }
        if(i < n){
            int x = m[s[i]];
            ans += x;
        }
        return ans;
    }
};