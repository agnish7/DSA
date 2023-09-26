class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        posSpeed = [[position[i], speed[i]] for i in range(len(speed))]
        posSpeed.sort(key = lambda a: a[0], reverse = True)
        stack = deque()
        
        def clash(ps1, ps2):
            if ps1[1] == ps2[1]:
                return ps1[0] == ps2[0]
            else:
                t = float(ps2[0] - ps1[0]) / float(ps1[1] - ps2[1])
                # print(ps1[0], ps1[1], ps2[0], ps2[1])
                x = float(ps1[0]) + float(ps1[1]) * t
                # print(t, x)
                return t >= 0 and x <= target
        
        for i in range(len(position)):
            if i == 0:
                stack.append(i)
                continue
            # print(i, stack)
            # print(posSpeed[i], posSpeed[stack[-1]])
            if clash(posSpeed[i], posSpeed[stack[-1]]):
                continue
            else:
                stack.append(i)
            
        return len(stack)
