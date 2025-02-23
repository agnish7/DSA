class Solution {
    vector<int> cumSum;
public:
    Solution(vector<int>& w) {
        cumSum.resize(w.size());
        partial_sum(w.begin(), w.end(), cumSum.begin());
    }
    
    int pickIndex() {
        int r = rand() % cumSum[cumSum.size() - 1];
        auto i = upper_bound(cumSum.begin(), cumSum.end(), r);
        return distance(cumSum.begin(), i);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

