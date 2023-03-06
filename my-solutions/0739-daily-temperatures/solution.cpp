class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temp_idx;
        vector<int> result(size(temperatures), -1);
        temp_idx.push(std::pair<int, int>(temperatures[0], 0));
        for(int i = 1; i < size(temperatures); i++) {
            while(!temp_idx.empty() && temperatures[i] > temp_idx.top().first) {
                result[temp_idx.top().second] = i - temp_idx.top().second;
                temp_idx.pop();
            }
            temp_idx.push(std::pair<int, int>(temperatures[i], i));
        }
        while(!temp_idx.empty()) {
            result[temp_idx.top().second] = 0;
            temp_idx.pop();
        }
        return result;
    }
};
