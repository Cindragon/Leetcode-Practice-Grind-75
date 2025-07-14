class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

/*
dp數組：二維數組，dp[i][j]的含義代表走到這一格有多少種路徑
遞推公式：dp[i][j]=dp[i-1][j]+dp[i][j-1]，因為只能向右跟向下走，
所以走到指定格子只有從上面往下走，以及從左邊往右邊走兩種方式
初始化：最上面一排跟最左邊一排都初始化為1，因為各只有一種方法(一路向右跟一路向下)
接下來進行迴圈遍歷，從左至右，再從上至下
最後回傳指定格子(dp[m-1][n-1])
*/