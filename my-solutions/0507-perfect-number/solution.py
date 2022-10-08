class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False
        sum = 1
        for i in range(2, int(sqrt(num)) + 1):
            if num % i == 0:
                sum += i + num / i
                
        if sum == num:
            return True
        else:
            return False
