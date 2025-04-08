class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto [start, end] = equal_range(nums.begin(), nums.end(), target);
        if(start == end) return {-1, -1};
        return {static_cast<int>(distance(nums.begin(), start)), static_cast<int>(distance(nums.begin(), end) - 1)};
    }
};
