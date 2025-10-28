class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans=[]
        def backtracking(path, Sum, startIndex):
            if len(path)==k and Sum==n:
                ans.append(path[:])
                return
            for i in range(startIndex, 10):
                if Sum+i>n:
                    break
                path.append(i)
                backtracking(path, Sum+i, i+1)
                path.pop()

        backtracking([], 0, 1)
        return ans