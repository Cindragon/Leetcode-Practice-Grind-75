class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        i, j=0, len(nums)-1
        n=len(nums)
        res=[0]*n
        pos=len(nums)-1

        while i<=j:
            if nums[i]*nums[i]<nums[j]*nums[j]:
                res[pos]=nums[j]*nums[j]
                j-=1
            else:
                res[pos]=nums[i]*nums[i]
                i+=1
            pos-=1
        return res