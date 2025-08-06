class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int currArea = 0;

        int l = 0, r = size(height) - 1;
        while(l < r) {
            currArea = min(height[l], height[r]) * (r - l);
            if(height[l] < height[r]) ++l;
            else --r;
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};
