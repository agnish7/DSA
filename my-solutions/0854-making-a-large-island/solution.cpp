class Solution {
    unordered_map<int, int> areaMap; // island label : area
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int label = 1;
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == 1) {
                    int area = islandArea(r, c, ++label, grid);
                    areaMap[label] = area;
                }
            }
        }

        int maxArea = 0;
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == 0) {
                    unordered_set<int> visited{};
                    int area = 1;
                    for(auto& dir: directions) {
                        int x = r + dir[0];
                        int y = c + dir[1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0 && !visited.count(grid[x][y])) {
                            visited.insert(grid[x][y]);
                            area += areaMap[grid[x][y]];
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea ? maxArea : m * n;

        // for(auto& r: grid) {
        //     for(auto& e: r) {
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }

        // for(auto& [k, v]: areaMap) {
        //     cout << k << " " << v << endl;
        // }

        // return -1;
    }

    // dfs code to find island area and mark with label
    int islandArea(int r, int c, int label, vector<vector<int>>& grid) {
        grid[r][c] = label;
        int m = grid.size(), n = grid[0].size();

        int res = 1;
        for(auto& dir: directions) {
            int x = r + dir[0];
            int y = c + dir[1];
            if(x >= 0 & x < m && y >= 0 && y < n && grid[x][y] == 1) {
                res += islandArea(x, y, label, grid);
            }
        }

        return res;
    }
};
