class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for(int i = 0; i < size(nums); i++){
            if(num_map.find(nums[i]) == num_map.end()){
                num_map[target - nums[i]] = i;
            } else {
                vector<int> res;
                res.push_back(i);
                res.push_back(num_map[nums[i]]);
                return res;
            }
        }
        return vector<int>{0, 0};
    }
};
