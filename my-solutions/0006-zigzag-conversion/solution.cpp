class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> mat(numRows, "");
        if(numRows == 1) return s;
        bool up = false; int r = 0;
        for(int i = 0; i < s.size(); ++i) {
            mat[r].push_back(s[i]);
            if(r == numRows - 1) up = true;
            if(r == 0) up = false;
            if(up) --r;
            else ++r;

        }

        string res = "";
        for(int i = 0; i < numRows; ++i) {
            res += mat[i];
        }

        return res;
    }
};
