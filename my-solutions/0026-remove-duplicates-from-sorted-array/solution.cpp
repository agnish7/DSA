class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        int unique = 1;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != nums[j]) {++j;++unique;}
            nums[j] = nums[i];
        }
        return unique;
    }
};
