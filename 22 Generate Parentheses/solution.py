from typing import List

class Solution:

    cache = list()

    def addNextChar(self, curr_str : str, open_count : int, limit : int, total_open : int):
        if limit == len(curr_str): 
            self.cache.append(curr_str)
            return
        if open_count > 0:
            self.addNextChar(curr_str + ")", open_count - 1, limit, total_open)
        if open_count + 1 <= limit / 2 and total_open + 1 <= limit / 2:
            self.addNextChar(curr_str + "(", open_count + 1, limit, total_open + 1)

    def generateParentheses(self, n : int) -> List[str]:
        self.cache.clear()
        start = "("
        self.addNextChar(start, 1, n * 2, 1)
        return self.cache


for gen in Solution().generateParentheses(1):
    print(gen, end = ", ")
print()