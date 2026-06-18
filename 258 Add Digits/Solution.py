

class Solution:
    def addDigits(self, num: int) -> int:
        out = 0
        temp = str(num)
        for ch in temp:
            out += int(ch)
        return out if out < 10 else self.addDigits(out)
    

print(Solution().addDigits(2032610959))