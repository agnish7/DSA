class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        
        i, j = 0, 0
        m, n = len(matrix), len(matrix[0])
        printed = 0
        
        dir = 'right'
        hor = n
        ver = m-1
        while(printed < m * n):
            
            if(dir == 'right'):
                for idx in range(hor):
                    res.append(matrix[i][j])
                    j += 1
                    printed += 1
                    
                if(printed >= m*n):
                    return res
                
                j -= 1
                i += 1
                hor -= 1
                dir = 'down'
                
            if(dir == 'down'):
                for idx in range(ver):
                    res.append(matrix[i][j])
                    i += 1
                    printed += 1
                
                if(printed >= m*n):
                    return res
                    
                i -= 1
                j -= 1
                ver -= 1
                dir = 'left'

            if(dir == 'left'):
                for idx in range(hor):
                    res.append(matrix[i][j])
                    j -= 1
                    printed += 1
                
                if(printed >= m*n):
                    return res
                    
                j += 1
                i -= 1
                hor -= 1
                dir = 'up'
                
            if(dir == 'up'):
                for idx in range(ver):
                    res.append(matrix[i][j])
                    i -= 1
                    printed += 1
                
                if(printed >= m*n):
                    return res

                i += 1
                j += 1
                ver -= 1
                dir = 'right'


        return res
