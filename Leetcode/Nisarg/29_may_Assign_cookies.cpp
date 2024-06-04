class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int i = 0, j = 0, m = g.size(), n = s.size();
        // int mini = min(m,n);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(i = 0, j = 0; i < m && j < n;){
            if(s[j] >= g[i]){
                i++;
                ans++;
            }
            j++;
        }
        return ans;
    }
};