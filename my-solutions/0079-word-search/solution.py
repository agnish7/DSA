class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        visited = set()
        def search(r, c, word):
            if (
                r < 0 or
                c < 0 or
                r > len(board) - 1 or
                c > len(board[0]) - 1 or
                word[0] != board[r][c] or
                (r, c) in visited
            ):
                # print(False, word, [r, c])
                return False
            elif len(word) == 1 and word[0] == board[r][c]:
                # print(True, word, [r, c])
                return True
            else:
                # print("searching", word, [r, c])
                visited.add((r, c))
                res = (
                    search(r-1, c, word[1:]) or
                    search(r+1, c, word[1:]) or
                    search(r, c+1, word[1:]) or 
                    search(r, c-1, word[1:])
                )
                visited.remove((r, c))
                return res

        # for i in range(len(board)):
        #     for j in range(len(board[0])):
        #         visited = set()
        #         if search(i,j, word, [i, j]):
        #             return True
        count = defaultdict(int, sum(map(Counter, board), Counter()))
        if count[word[0]] > count[word[-1]]:
            word = word[::-1]
        for i in range(len(board)):
            for j in range(len(board[0])):
                if search(i, j, word):
                    return True

        return False

