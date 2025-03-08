class Solution {
public:
    string simplifyPath(string path) {
        path = path + "/";
        stack<string> dirs;
        string currDir = "";
        string res = "";

        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') {
                if(currDir.size() != 0) {
                    if(currDir == "..") {
                        if(!dirs.empty()) dirs.pop();
                    } else if (currDir == ".") {
                        // do nothing
                    } else {
                        dirs.push(currDir);
                    }
                }
                currDir = "";
            } else {
                currDir += path[i];
            }
        }


        while(!dirs.empty()) {
            res = "/" + dirs.top() + res;
            dirs.pop();
        }

        return res == "" ? "/" : res;
    }
};
