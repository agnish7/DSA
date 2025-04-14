class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> digit_to_letters {
            {1, ""},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        deque<string> q{};

        for(int i = 0; i < digits.size(); ++i) {

            string letters = digit_to_letters[digits[i] - '0'];

            if(i == 0) {
                for(auto& letter: letters) q.push_back(string(1, letter));
                continue;
            }

            int qSize = q.size();

            for(int j = 0; j < qSize; ++j) {
                string combo = q.front();
                q.pop_front();
                for(auto& letter: letters) {
                    q.push_back(combo + letter);
                }
            }
        }

        return vector<string> (q.begin(), q.end());
    }
};
