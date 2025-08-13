class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n=len(arr)
        left, right=0, n-1

        while left+1<n and arr[left]<arr[left+1]:
            left+=1
        
        while right-1>=0 and arr[right-1]>arr[right]:
            right-=1
    
        return left>0 and right<n-1 and left==right
        