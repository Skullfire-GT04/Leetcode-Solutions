class Solution:

    def lengthOfLongestSubstring(self, s : str) -> int:
        if len(s) < 1: return 0
        out = 1
        last_max_sub = out
        while out <= len(s):
            found_sub = False
            i = 0
            while i <= len(s) - out:
                temp = dict()
                sub = s[i:i + out]
                found_it = True
                for ch in sub:
                    if temp.get(ch, None):
                        found_it = False
                        break
                    else:
                        temp[ch] = ch
                if found_it:
                    found_sub = True
                    break
                i += 1
            if found_sub: 
                last_max_sub = out
                out += 1
            else: break
        return last_max_sub
    

print(Solution().lengthOfLongestSubstring("au"))
            



        


