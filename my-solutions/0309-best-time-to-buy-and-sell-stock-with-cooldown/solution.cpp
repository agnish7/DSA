class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> res(2, vector<int>(prices.size() + 2, 0));
        for(int i = prices.size() - 1; i > -1; --i) {
            res[1][i] = max(prices[i] + res[0][i + 2], res[1][i + 1]);
            res[0][i] = max(-prices[i] + res[1][i + 1], res[0][i + 1]);
        }
        return max(res[0][1], res[0][0]); 
    }
};
