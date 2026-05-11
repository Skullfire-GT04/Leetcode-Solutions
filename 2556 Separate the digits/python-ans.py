from typing import List

class Solution:
    def separateDigits(self, nums : List[int]) -> List[int]:
        out = []
        for num in nums:
            for ch in str(num):
                out.append(int(ch))
        return out


print(Solution().separateDigits([13, 25, 83, 77]))