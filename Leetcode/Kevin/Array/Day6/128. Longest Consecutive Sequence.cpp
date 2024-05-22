// Link ::  https://leetcode.com/problems/longest-consecutive-sequence/

// Not so efficient solution (Time Limit Exceeded)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int max = 0;

        for(int n : nums){
            if(mp[n])
                continue;

            mp[n] = mp[n-1] + mp[n+1] + 1;
            int x = n;
            while(mp[--x]){
                mp[x] = mp[n];
            }
            x = n;
            while(mp[++x]){
                mp[x] = mp[n];
            }
            
            if(mp[n] > max){
                max = mp[n];
            }
        }

        return max;

        
    }
};


// beeter approach

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
           int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

        
    }
};