class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n<=0: return False
        i=1
        while i<=n:
            if i==n:
                return True
            i*=4
        return False