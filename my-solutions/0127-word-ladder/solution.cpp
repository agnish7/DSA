class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto i = find(wordList.begin(), wordList.end(), endWord);
        if(i == wordList.end()) return 0;

        int ewIdx = distance(wordList.begin(), i);

        // cout << ewIdx << endl;

        int bwIdx = -1;
        i = find(wordList.begin(), wordList.end(), beginWord);
        if(i != wordList.end()) bwIdx = distance(wordList.begin(), i);
        else {
            wordList.push_back(beginWord);
            bwIdx = wordList.size() - 1;
        }

        // cout << bwIdx << endl;

        unordered_map<int, unordered_set<int>> adjList;

        for(int i = 0; i < wordList.size(); ++i) {
            for(int j = i + 1; j < wordList.size(); ++j) {
                if(diff(wordList[i], wordList[j])){
                    adjList[i].insert(j);
                    adjList[j].insert(i);
                }
            }
        }

        // for(auto& [k, v]: adjList) {
        //     cout << k << ": ";
        //     for(auto& j: v) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }

        // cout << endl;


        queue<int> q;
        q.push(bwIdx);

        unordered_set<int> visited;

        int distance = 1;

        while(!q.empty()) {
            ++distance;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                int node = q.front();
                visited.insert(node);
                q.pop();
                // cout << node << ": ";
                for(auto& neighbour: adjList[node]) {
                    // cout << neighbour << " ";
                    if(neighbour == ewIdx) return distance;
                    if(!visited.count(neighbour)) q.push(neighbour);
                }
                // cout << endl;
            }
        }

        return 0;
    }
    bool diff(string& a, string& b) {
        int diff = 0;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] != b[i]) ++diff;
        }
        return diff == 1; 
    }
};
