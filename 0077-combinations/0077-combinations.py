class Solution:
    def __init__(self):
        self.path=[]
        self.ans=[]
    def backtracking(self, n:int, k:int, startIndex:int):
        if len(self.path)==k:
            self.ans.append(self.path[:])
            return
        for i in range (startIndex, n-(k-len(self.path))+2):
            self.path.append(i)
            self.backtracking(n, k, i+1)
            self.path.pop()
        return
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.backtracking(n, k, 1)
        return self.ans

'''
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        def backtrack(path, val):
            if len(path) == k:
                result.append(path[:])
                return 

            for i in range(val, n+1):
                path.append(i)
                backtrack(path, i+1)
                path.pop()
                
        backtrack([], 1)
        return result
'''