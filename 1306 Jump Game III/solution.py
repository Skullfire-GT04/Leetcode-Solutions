from typing import List


class Solution:
    visited = list()
    nodes = list()

    def recursiveVisit(self, index):
        if(self.visited[index]): return
        self.visited[index] = True
        right_index = self.nodes[index] + index
        left_index = index - self.nodes[index]

        if right_index < len(self.nodes): self.recursiveVisit(right_index)
        if left_index >= 0: self.recursiveVisit(left_index)

    def canReach(self, arr : List[int], start : int) -> bool:
        self.visited = [False for i in range(len(arr))]
        self.nodes = arr.copy()
        self.recursiveVisit(start)

        for i in range(len(arr)):
            if not arr[i] and self.visited[i]: return True
        return False
            



print(Solution().canReach([4, 2, 3, 0, 3, 1, 2], 5))