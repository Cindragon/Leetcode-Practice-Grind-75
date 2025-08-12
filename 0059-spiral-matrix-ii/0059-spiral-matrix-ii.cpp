class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int count=1, offset=1;
        int loop=n/2;
         int mid=n/2;
        int startx=0, starty=0;
        int i, j;
        while(loop--){
            i=startx;
            j=starty;
            for(j=starty;j<n-offset;j++){
                res[startx][j]=count++;
            }
            for(i=startx;i<n-offset;i++){
                res[i][j]=count++;
            }
            for(;j>starty;j--){
                res[i][j]=count++;
            }
            for(;i>startx;i--){
                res[i][j]=count++;
            }
            startx++;
            starty++;
            offset++;
        }
        if(n%2==1){
            res[mid][mid]=n*n;
        }
        return res;
    }
};

/*
最困難的部分在於怎麼將數字加入矩陣中
運用左閉右開的方式來限制加入數字的順序
count 為要加入的數, offset 代表每次都要往裡面縮幾圈
loop 代表要轉幾圈，mid 則是最中間那一格，startx 跟 starty 則是起點,i 跟 j 則代表 res [i][j]
在 loop 不為 0 的情況下，i, j 從起點開始
最上面：右邊往內縮一個 offset
最右邊：下面往內縮一個 offset
以此類推
最後 offset+1(往內縮第二圈)，startx 跟 starty 都加 1(新的起點)
如果 n 為奇數，最中間那格不會被遍歷到，再 assign 一個值給他
*/