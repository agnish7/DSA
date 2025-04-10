class Solution {
public:
    int climbStairs(int n) {
        int* res = new int[n + 1];
        res[1] = 1;
        res[0] = 1;
        for(int i = 2; i < n + 1; ++i) {
            res[i] = res[i - 1] + res[i - 2];
        }
        int result = res[n];
        delete[] res;
        return result;
    }
};
