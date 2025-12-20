class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        ans = 0
        for i in range(len(strs[0])):
            s = ''.join(x[i] for x in strs)
            if list(s) != sorted(list(s)):
                ans += 1

        return ans


        
        