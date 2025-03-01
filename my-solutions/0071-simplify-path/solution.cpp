class Solution {
public:
    string simplifyPath(string path) {
        stack<string> parts;
        int start = false;
        string part = "";
        for(int i = 0; i <= path.size(); ++i) {
            if(path[i] == '/' || i == path.size()) {
                if(part != "" && part != ".") {
                    cout << part << endl;
                    if(part == "..") {
                        if(!parts.empty()) parts.pop();
                    } else {
                        parts.push(part);
                    }
                }
                part = "";
            } else {
                part += path[i];
            }
        }

        string res = "";
        while(!parts.empty()) {
            res = "/" + parts.top() + res;
            parts.pop();
        }
        return res != "" ? res : "/";
    }
};
