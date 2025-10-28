class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ans=[]
        letterMap={
            '2': "abc", '3': "def", '4': "ghi", '5': "jkl",
            '6': "mno", '7': "pqrs", '8': "tuv", '9': "wxyz"
        }
        def backtracking(path, index):
            if index==len(digits):
                ans.append(''.join(path))
                return
            digit=digits[index]
            letters=letterMap[digit]
            for ch in letters:
                path.append(ch)
                backtracking(path, index+1)
                path.pop()
        backtracking([], 0)
        return ans