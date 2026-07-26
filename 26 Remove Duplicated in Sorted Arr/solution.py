from typing import List


class Solution:

    def removeDuplicates(self, nums : List[int]) -> int:
        swap = 0
        comp = 0
        curr_num = nums[0]
        n = len(nums)
        k = 1
        while comp < n:
            if nums[comp] != curr_num:
                curr_num = nums[comp]
                k += 1
                swap += 1
                nums[swap] = curr_num
            comp += 1
        return k


nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
print(Solution().removeDuplicates(nums))
print(nums)
