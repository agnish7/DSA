class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for(int i = 0; i < size(nums); i++){
            if(num_set.find(nums[i]) != num_set.end()) {
                return true;
            } else {
                num_set.insert(nums[i]);
            }
        }
        return false;
    }
};
