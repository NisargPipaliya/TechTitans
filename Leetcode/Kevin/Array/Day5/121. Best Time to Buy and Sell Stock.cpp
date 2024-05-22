// Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int n = prices.size();
        int minp = INT_MAX;
        for(int i=0;i<n;i++)
        {
            minp = min(minp, prices[i]);
            maxPro = max(maxPro, prices[i] - minp);
        }

        return maxPro;
    }

}