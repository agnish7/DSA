class Solution {
    int MOD = 1000000007;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        int res = 0;
        for(int i = min(zero, one); i <= high; ++i) {
            if(i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD ;
            }
            if(i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
        }

        for(int i = low; i <= high; ++i) {
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};
