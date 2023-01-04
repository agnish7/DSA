class Solution:
    def reverseBits(self, n: int) -> int:
        s = str(bin(n))[::-1][:-2]
        s = s + "0" * (32 - len(s))
        return int(s, 2)
