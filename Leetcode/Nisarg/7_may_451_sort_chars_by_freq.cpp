#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
     map<char,int> m;
     for(char i : s)   {
        m[i]++;
     }
     string ans;
     vector<pair<int,char>> v;
     for(auto i : m){
        v.emplace_back(make_pair(i.second,i.first));
     }
     sort(v.begin(),v.end());
     reverse(v.begin(),v.end());
     for(auto i : v){
        int c = i.first;
        while(c > 0){
            ans.push_back(i.second);
            c--;
        }
     }

     return ans;
    }
};
