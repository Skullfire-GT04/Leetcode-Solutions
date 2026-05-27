class Solution:
    def numberOfSpecialCharacters(self, word: str) -> int:
        temp = dict()
        is_valid = [True for _ in range(26)]
        count = 0
        for ch in word:
            if not temp.get(ch, None):
                temp[ch] = 1
            if ch.islower():
                if temp.get(ch.upper(), None):
                    is_valid[ord(ch) - ord('a')] = False
        for i in range(26):
            char = chr(i + ord('a'))
            if temp.get(char, None) and temp.get(char.upper(), None) and is_valid[i]:
                count += 1
        return count


print(Solution().numberOfSpecialCharacters("AbBCab"))
        
        