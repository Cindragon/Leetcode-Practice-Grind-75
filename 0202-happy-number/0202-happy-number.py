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