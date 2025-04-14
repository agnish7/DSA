class Solution {
    int directions[8][2] = {
        {-1, 1}, {-1, 0}, {-1, -1},
        {0, 1}, {0, -1},
        {1, -1}, {1, 0}, {1, 1}
    };
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(click[0], click[1], board);
        return board;
    }

    void dfs(int r, int c, vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        int mines = 0;
        for(auto& dir: directions) {
            int x = dir[0] + r, y = dir[1] + c;
            if(x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 'M')) {
                ++mines;
            }
        }

        if(mines) {
            board[r][c] = '0' + mines;
            return;
        }

        board[r][c] ='B';

        for(auto& dir: directions) {
            int x = dir[0] + r, y = dir[1] + c;
            if(x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 'E')) {
                dfs(x, y, board);
            }
        }
    }
};
