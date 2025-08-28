class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        #return not (Counter(ransomNote) - Counter(magazine)) 一行解
        records={}
        for c in magazine:
            if c not in records:
                records[c]=0
            records[c]+=1
        for c in ransomNote:
            if c not in records or records[c]<=0:
                return False
            records[c]-=1
        return True