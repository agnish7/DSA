class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to unordered_set for O(1) lookups
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        // Separate visited set to avoid modifying wordSet
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int distance = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string node = q.front();
                q.pop();

                // Early termination if we reach endWord
                if (node == endWord) return distance;

                // Mark as visited
                if (visited.count(node)) continue;
                visited.insert(node);

                // Generate neighbors efficiently
                for (int j = 0; j < node.size(); ++j) {
                    string neighbor = node; // Copy once per position
                    for (char c = 'a'; c <= 'z'; ++c) {
                        neighbor[j] = c;
                        if (wordSet.count(neighbor) && !visited.count(neighbor)) {
                            q.push(neighbor);
                        }
                    }
                }
            }
            ++distance;
        }

        return 0;
    }
};
