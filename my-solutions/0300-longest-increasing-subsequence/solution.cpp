class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> cache(size(nums), 1);
        for(int i = 1; i < size(nums); i++) {
            int max = 1;
            int temp = 0;
            for(int j = 0; j < i; j++) {
                temp = nums[i] > nums[j] ? 1 + cache[j] : 0;
                max = std::max(max, temp);
            }
            cache[i] = max;
        }
        // for(const auto& i: cache) {
        //     cout << i << " ";
        // }
        return *std::max_element(cache.begin(), cache.end());
    }
};
