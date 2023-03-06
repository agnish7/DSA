class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> word_map;
        for(int i = 0; i < size(words); i++) {
            word_map[words[i]]++;
        }

        map<int, vector<string>, greater<int>> freq_map;
        for(const auto& i: word_map) {
            freq_map[i.second].push_back(i.first);
        }

        vector<string> result;
        for(const auto&i: freq_map) {
            vector<string> temp(i.second);
            sort(temp.begin(), temp.end());
            for(int i = 0; i < size(temp); i++) {
                result.push_back(temp[i]);
                k--;
                if(k == 0) return result;
            }
        }

        // for(const auto& i: freq_map) {
        //     cout << i.first << ": ";
        //     for(const auto& j: i.second) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }


        return result;
    }
};
