class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);
        int res = 0;

        int currMax = 0;
        for(int i = 0; i < n; ++i) {
            maxLeft[i] = currMax;
            currMax = max(currMax, height[i]);
        }

        currMax = 0;
        for(int i = n - 1; i > -1; --i) {
            maxRight[i] = currMax;
            currMax = max(currMax, height[i]);
        }

        for(int i = 0; i < n; ++i) {
            int maxWater = min(maxLeft[i], maxRight[i]);
            res += maxWater > height[i] ? maxWater - height[i] : 0;
        }

        return res;
    }
};
