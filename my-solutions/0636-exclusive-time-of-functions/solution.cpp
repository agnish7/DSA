class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> waiting;
        int currProc = -1;
        int currTime = 0;

        vector<int> res(n, 0);
        for(auto& log: logs) {
            int pid = 0, start = 0, timestamp = 0;
            parseLog(log, &pid, &start, &timestamp);

            if(start) {
                if(currProc != -1) {
                    waiting.push(currProc);
                    res[currProc] += timestamp - currTime;
                }
                currProc = pid;
                currTime = timestamp;
            } else {
                res[currProc] += timestamp - currTime + 1;
                currTime = timestamp + 1;
                if(!waiting.empty()) {
                    currProc = waiting.top();
                    waiting.pop();
                }
            }
        }
        return res;
    }

    void parseLog(string& log, int* pid, int* start, int* timestamp) {
        int i = log.find(':', 0);
        *pid = stoi(log.substr(0, i));
        int i2 = log.find(':', i + 1);
        string temp = log.substr(i + 1, i2 - i - 1);
        *start = (temp == "start" ? 1 : 0);
        *timestamp = stoi(log.substr(i2 + 1, log.size() - i2 - 1));
    }
};
