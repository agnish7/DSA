class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int n = nums.size();
        int j = -1;
        for(int i = n - 2; i > -1; --i) {
            if(nums[i] < nums[i + 1]) {
                j = i;
                break;
            }
        }
        if(j == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        reverse(nums.begin() + j + 1, nums.end());
        auto it = upper_bound(nums.begin() + j + 1, nums.end(), nums[j]);
        swap(nums[distance(nums.begin(), it)], nums[j]);
        return;
    }
};
