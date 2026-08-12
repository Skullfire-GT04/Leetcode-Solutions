from typing import List


class Solution:

    def weightedSum(self, parent: list[int], nums: list[int]) -> int:
        child_list = dict()
        for i in range(1, len(parent)):
            if not child_list.get(parent[i], None):
                child_list[parent[i]] = list()
            child_list[parent[i]].append(i)
        summation = 0
        sub = 0
        for num in nums: summation += num
        queue = [0]
        height = 0
        next_row = list()
        while len(queue):
            sub += nums[queue[0]] * (height + 1)
            if child_list.get(queue[0], None):
                next_row.extend(child_list[queue.pop(0)])
            else: queue.pop(0)
            if not len(queue):
                queue.extend(next_row)
                next_row.clear()
                height += 1 
        
        return (summation * (height + 1)) - sub
    

parent = [-1,0,1,2]
nums = [1,2,3,4]
print(Solution().weightedSum(parent, nums))