class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res=[[0]*n for _ in range(n)]
        loop=n//2
        mid=n//2
        startx, starty=0,0
        count=1
        offset=1
        
        for offset in range(1, loop+1): #每循環一圈 offset+1
            for i in range(starty, n - offset): #從左到右
                res[startx][i]=count
                count+=1

            for i in range(startx, n-offset):   #從上到下
                res[i][n-offset]=count
                count+=1

            for i in range(n-offset, starty, -1):   #從右到左
                res[n-offset][i]=count
                count+=1

            for i in range(n-offset, startx, -1):   #從下到上
                res[i][starty]=count
                count+=1
            
            startx+=1 #更新起始點
            starty+=1

        if n%2==1:
            res[mid][mid]=n*n
        return res


