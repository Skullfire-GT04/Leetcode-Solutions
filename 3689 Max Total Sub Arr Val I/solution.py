from typing import List


class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        curr_max = 0
        curr_min = 10e9
        for i in range(len(nums)):
            if nums[i] > curr_max: curr_max = nums[i]
            if nums[i] < curr_min: curr_min = nums[i]
        return k * (curr_max - curr_min)