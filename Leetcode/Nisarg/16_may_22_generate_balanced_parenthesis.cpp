#include<vector>
#include<string>
using namespace std;

class Solution {
    void help(int open, int close, string curr, vector<string> &ans){
        if(open == 0 && close == 0){
            ans.emplace_back(curr);
            return;
        }
        if(open == close){
            curr += '(';
            open--;
            help(open,close,curr,ans);
        }else if(open != 0 && open < close){
            curr += '(';
            open--;
            help(open,close,curr,ans);
            curr.pop_back();
            open++;
            curr += ')';
            close--;
            help(open,close,curr,ans);
        }else if(open == 0){
            curr += ')';
            close--;
            help(open,close,curr,ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        help(n,n,curr,ans);
        return ans;
    }
};