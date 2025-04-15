class Solution {
public:
    string customSortString(string order, string s) {
        unordered_set<char> order_set(order.begin(), order.end());
        for(auto& c: s) {
            if(!order_set.count(c)) {
                order.push_back(c);
                order_set.insert(c);
            }
        }

        unordered_map<char, int> letter_to_count;

        for(auto& c: s) {
            ++letter_to_count[c];
        }

        string res{};

        for(auto& c: order) {
            if(letter_to_count.count(c)) {
                res += string(letter_to_count[c], c);
            }
        }

        return res;
    }
};
