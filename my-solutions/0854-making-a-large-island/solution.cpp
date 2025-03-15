class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int label = 2;
        unordered_map<int, int> sizeMap; // Label -> size
        
        // Step 1: Label all islands and compute sizes in one pass
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) { // Only DFS on unmarked 1s
                    int size = dfs(grid, i, j, n, label);
                    sizeMap[label] = size;
                    ++label;
                }
            }
        }
        
        // Step 2: Base max size (largest existing island or 0 if none)
        int maxSize = 0;
        for (auto& [_, size] : sizeMap) {
            maxSize = max(maxSize, size);
        }
        
        // Step 3: Try changing each 0 to 1
        static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int seen[4] = {0}; // Track up to 4 unique neighbor labels
                    int size = 0, seenCount = 0;
                    for (auto& d : dirs) {
                        int r = i + d[0];
                        int c = j + d[1];
                        if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] >= 2) {
                            int islandLabel = grid[r][c];
                            bool isNew = true;
                            for (int k = 0; k < seenCount; ++k) {
                                if (seen[k] == islandLabel) {
                                    isNew = false;
                                    break;
                                }
                            }
                            if (isNew) {
                                size += sizeMap[islandLabel];
                                seen[seenCount++] = islandLabel;
                            }
                        }
                    }
                    maxSize = max(maxSize, 1 + size);
                }
            }
        }
        
        // If grid is all 0s or all 1s, handle edge cases
        return (maxSize == 0 && n > 0) ? 1 : maxSize;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int r, int c, int n, int label) {
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) return 0;
        grid[r][c] = label; // Mark with label
        static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int size = 1;
        for (auto& d : dirs) {
            size += dfs(grid, r + d[0], c + d[1], n, label);
        }
        return size;
    }
};
