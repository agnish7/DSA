class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map (size(nums));
        for(int i = 0; i < size(nums); i++) {
            if(map.find(nums[i]) != map.end()) {
                return vector<int>({i, map[nums[i]]});
            }
            map[target - nums[i]] = i;
        }
        return vector<int>({});
    }
};
