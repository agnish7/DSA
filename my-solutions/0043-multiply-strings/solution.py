class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        a, b = num1[::-1], num2[::-1]

        m, n = len(a), len(b)

        digits = [0] * (m + n)

        for i in range(m):
            for j in range(n):

                pos = i + j

                existing = digits[pos]

                mul = int(a[i]) * int(b[j])

                total = mul + existing

                total_digit = total % 10

                total_carry = total // 10

                digits[pos] = total_digit

                digits[pos + 1] += total_carry

        while len(digits) > 1 and digits[-1] == 0:
            digits.pop()

        return "".join(map(str, digits[::-1]))

        return ""



