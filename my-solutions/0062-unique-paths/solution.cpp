class Solution {
public:
    int uniquePaths(int m, int n) {
        return binomialCoeff(m + n - 2, m - 1);
    }
    long long binomialCoeff(int n, int r) {
    if (r > n - r) {
        r = n - r;
    }

    long long res = 1;
    for (int i = 0; i < r; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}
};
