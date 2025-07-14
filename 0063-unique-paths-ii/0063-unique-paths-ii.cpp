class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1) break;
            else dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]==1) break;
            else dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) continue;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

/*
跟不同路徑一樣，只是現在多了一個障礙需要避開
如果起點或終點有障礙物的話回傳0，代表根本走不到
設立dp數組：大小跟obstacleGrid一樣
遍歷公式：一樣為 dp[i][j]=dp[i-1][j]+dp[i][j-1]
接著進行初始化，將數組的所有數設為0
第一列跟第一行初始化為1，若是遇到障礙物則結束迴圈
接著運用迴圈從左至右，從上往下進行遍歷
若是遇到障礙物就直接繼續遍歷，不然就是繼續加總
最後回傳 dp[m-1][n-1]
*/