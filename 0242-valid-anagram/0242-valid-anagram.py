class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        alphaCount=[0]*26
        for c in s:
            alphaCount[ord(c)-ord('a')]+=1
        for c in t:
            alphaCount[ord(c)-ord('a')]-=1
        for i in alphaCount:
            if i!=0:
                return False
        return True
            