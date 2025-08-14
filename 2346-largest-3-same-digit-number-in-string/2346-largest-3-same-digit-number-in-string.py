class Solution:
    def largestGoodInteger(self, num: str) -> str:
        ans=""
        for i in range(len(num)-2):
            if num[i]==num[i+1] and num[i]==num[i+2]:
                temp=num[i:i+3]
                if temp>ans:
                    ans=temp
        return ans