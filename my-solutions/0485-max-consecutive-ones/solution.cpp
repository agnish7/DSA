class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int maxOnes = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]) sum += nums[i];
            else sum = 0;
            maxOnes = max(maxOnes, sum);
        }
        return maxOnes;
    }
};
