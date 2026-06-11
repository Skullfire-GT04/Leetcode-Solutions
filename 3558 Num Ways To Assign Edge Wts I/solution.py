from typing import List


class Solution:

    def recursiveVisit(self, edges, curr_node, max_depth):
        if not edges.get(curr_node, None): return max_depth
        curr_max = max_depth
        max_depth += 1
        for child in edges[curr_node]:
            temp = self.recursiveVisit(edges, child, max_depth)
            curr_max = max(temp, curr_max)
        return curr_max

    def assignEdgeWeights(self, edges : List[List[int]]) -> int:
        children = {}

        for edge in edges:
            if children.get(edge[0], None):
                children[edge[0]].append(edge[1])
            else: children[edge[0]] = [edge[1]]

        for key, val in children.items(): print(key, val)

        max_depth = self.recursiveVisit(children, 1, 0)
        return (2 ** (max_depth - 1)) % (10 ** 9 + 7)
    


print(Solution().assignEdgeWeights([[3, 2], [1, 2]]))
        

