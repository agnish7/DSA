class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0, j = 0, res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(!nums[i]) ++zeros;
            while(zeros > k) {
                if(!nums[j]) --zeros;
                ++j;
            }
            // cout << i << " " << j << " " << zeros << endl;
            res = max(res, i - j + 1);
        }
        return res;
    }
};
