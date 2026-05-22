from typing import List

class Solution:
    def longestCommonPrefix(self, arr1 : List[int], arr2 : List[int]) -> int:
        max_prefix = 0
        cache = {}
        for num1 in arr1:
            str_num1 = str(num1)
            for i in range(1, len(str_num1) + 1):
                cache[str_num1[:i]] = 1
        for num2 in arr2:
            str_num2 = str(num2)
            for i in range(len(str_num2), 0, -1):
                if cache.get(str_num2[:i], None): 
                    max_prefix = max(max_prefix, len(str_num2[:i]))
                    break
        return max_prefix

print(Solution().longestCommonPrefix([1, 10, 100], [1000]))
