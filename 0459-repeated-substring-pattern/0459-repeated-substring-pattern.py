class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n=len(s)
        next=[0]*n
        j=0
        for i in range(1, n):
            while j>0 and s[i]!=s[j]:
                j=next[j-1]
            if s[i]==s[j]:
                j+=1
            next[i]=j
        
        return next[-1]>0 and n%(n-next[-1])==0
#        return s in (s + s)[1:-1]