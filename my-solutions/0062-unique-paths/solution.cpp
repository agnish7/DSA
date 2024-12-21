class Solution {
public:
    int uniquePaths(int m, int n) {
    // For unique paths: total steps = m + n - 2, choose smaller of (m-1, n-1)
    int N = m + n - 2;
    int K = min(m - 1, n - 1);
    
    if (K < 0) return 0;
    if (K == 0) return 1;
    
    // Calculate C(N,K) using multiplicative formula
    long long result = 1;
    
    // Use the smaller of K and N-K due to symmetry C(N,K) = C(N,N-K)
    K = min(K, N - K);
    
    // Multiply first, then divide to maintain accuracy
    // Calculate as (N * (N-1) * ... * (N-K+1)) / (1 * 2 * ... * K)
    for (int i = 0; i < K; i++) {
        result = result * (N - i);
        result = result / (i + 1);
    }
    
    return result;
    }
};

