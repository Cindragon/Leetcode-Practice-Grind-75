class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        res=float('inf')
        i, sum_=0, 0
        for j in range(0, len(nums)):
            sum_+=nums[j]
            while sum_>=target:
                res=min(res, j-i+1)
                sum_-=nums[i]
                i+=1
        return 0 if res==float('inf') else res
        