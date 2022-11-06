class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // convert the array of numbers to a set.
        unordered_set<int> s(nums.begin(), nums.end());

        int max_len = 0;
        // find sequence starting numbers.
        for(int i = 0; i < size(nums); i++) {
            int curr_len = 1;
            if(s.find(nums[i] - 1) == s.end()) {
                int j = 1;
                while(s.find(nums[i] + j++) != s.end())
                    curr_len++;
            }
            cout << curr_len << endl;
            if(max_len < curr_len) {
                max_len = curr_len;
            }
        }

        return max_len;
    }
};
