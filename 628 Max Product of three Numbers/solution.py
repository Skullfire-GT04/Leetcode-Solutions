from typing import List


class Solution:

    def maximumProduct(self, nums : List[int]) -> int:
        max_indices = []
        for _ in range(3):
            curr_max = -1
            for i in range(len(nums)):
                if i in max_indices: continue
                if curr_max < 0 or nums[i] > nums[curr_max]: curr_max = i
            
            max_indices.append(curr_max)

        min_indices = []
        for _ in range(2):
            curr_min = -1
            for i in range(len(nums)):
                if i in min_indices: continue
                if curr_min < 0 or nums[i] < nums[curr_min]: curr_min = i
            min_indices.append(curr_min)

        result1 = 1
        for i in max_indices:
            result1 *= nums[i]

        result2 = nums[min_indices[0]] * nums[min_indices[1]] * nums[max_indices[0]]
        return max(result1, result2)


print(Solution().maximumProduct([-100,-98,-1,2,3,4]))