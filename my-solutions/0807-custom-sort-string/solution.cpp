class Solution {
public:
    string customSortString(string order, string s) {
        string res = "";
        vector<int> s_freq(26, 0);
        vector<int> order_freq(26, 0);
        for(auto& c: order) ++order_freq[c - 'a'];
        for(auto& c: s) ++s_freq[c - 'a'];
        for(auto& c: order) res += string(s_freq[c - 'a'], c);
        for(auto& c: s)if(!order_freq[c - 'a']) res += c;
        return res;
    }
};
