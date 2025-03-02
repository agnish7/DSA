class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_freq;
        for(auto& num: nums) {
            ++num_freq[num];
        }
        map<int, vector<int>, greater<int>> freq_num;
        for(auto& p: num_freq) {
            freq_num[p.second].push_back(p.first);
        }
        vector<int> res;
        for(auto& p: freq_num) {
            for(auto& i: p.second) {
                res.push_back(i);
                if(res.size() == k)
                    return res;
            }
        }
        return {};
    }
};
