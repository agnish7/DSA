class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        for i in range(len(board)):
            reps_rows = set()
            reps_cols = set()
            for j in range(len(board[0])):
                if board[i][j] != '.':
                    if board[i][j] in reps_rows:
                        print(reps_rows)
                        return False
                    else:
                        reps_rows.add(board[i][j])
                    
                if board[j][i] != '.':
                    if board[j][i] in reps_cols:
                        print(reps_cols)
                        return False
                    else:
                        reps_cols.add(board[j][i])
        
        for i in range(0, len(board), 3):
            for j in range(0, len(board[0]), 3):
                rep_box = set()
                for k in range(i, i+3):
                    for l in range(j, j+3):
                        if board[k][l] != '.':
                            if board[k][l] in rep_box:
                                print(rep_box)
                                return False
                            else:
                                rep_box.add(board[k][l])

        return True

