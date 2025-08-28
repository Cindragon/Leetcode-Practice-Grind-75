class Solution:
    def isHappy(self, n: int) -> bool:
        record=set()
        while n not in record:
            record.add(n)
            newNum=0
            n_str=str(n)
            for i in n_str:
                newNum+=int(i)**2
            if newNum==1:
                return True
            else:
                n=newNum
        return False

'''
使用集合的方式來計算 happy number
並且用轉換成 string 的方式來計算加總過後的數值
並且不斷更新原本的n，直到n=1或是出現在集合中
'''