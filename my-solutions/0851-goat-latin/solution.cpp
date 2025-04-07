class Solution {
public:
    string toGoatLatin(string sentence) {
        int l = 0, r = 0;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int i = 1;

        string res = "";

        while(r < sentence.size()) {
            r = sentence.find(' ', l);
            string word = sentence.substr(l, r - l);
            string newWord = "";
            if(vowels.count(word[0])) {
                newWord = word + "ma" + string(i, 'a');
            } else {
                newWord = word.substr(1, word.size() - 1) + word[0] + "ma" + string(i, 'a');
            }
            res += newWord + ' ';
            l = r + 1;
            ++i;
        }
        return res.substr(0, res.size() - 1);
    }
};
