from typing import List


class Solution:
    
    def twoSum(self, nums: List[int], target : int) -> List[int]:
        temp = dict()
        for index, num in enumerate(nums):
            if not temp.get(num, None):
                temp[num] = [index]
            else:
                temp[num].append(index)
        
        for num in temp.keys():
            new_target = target - num
            if temp.get(new_target, None):
                if new_target == num and len(temp.get(new_target)) >= 2:
                    return temp.get(new_target)[:2]
                elif new_target == num and len(temp.get(new_target)) < 2:
                    continue
                else:
                    return [temp.get(num)[0], temp.get(new_target)[0]]


print(Solution().twoSum([3, 2, 4], 6))