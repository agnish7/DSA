class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        # check row-wise
        for i in range(9):
            num_set = set()
            for j in range(9):
                if board[i][j] in num_set:
                    # print(num_set)
                    # print(i, j)
                    return False
                else:
                    if board[i][j] != ".":
                        num_set.add(board[i][j])

        # check column-wise
        for i in range(9):
            num_set = set()
            for j in range(9):
                if board[j][i] in num_set:
                    # print(num_set)
                    # print(i, j)
                    return False
                else:
                    if board[j][i] != ".":
                        num_set.add(board[j][i])

        # check box-wise
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                num_set = set()
                for i_delta in range(3):
                    for j_delta in range(3):
                        if board[i + i_delta][j + j_delta] in num_set:
                            return False
                        else:
                            if board[i + i_delta][j + j_delta] != ".":
                                num_set.add(board[i + i_delta][j + j_delta])


        return True
