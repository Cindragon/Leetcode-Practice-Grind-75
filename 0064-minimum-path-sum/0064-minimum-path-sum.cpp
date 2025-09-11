class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<n;i++){
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

/*
用動規五部曲的方式來寫
1. dp 數組定義：到 [i, j]這格路徑加總的最小值為dp[i][j]
2. 遞推公式：dp[i][j]=dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j];
找到上個狀態的最小值再加上現在這格的值。
3. 初始化：一開始 dp[0][0]=grid[0][0]
    一路往右走的值就是：dp[i][0]=dp[i-1][0]+grid[i][0];
    一路往下走的值就是：dp[0][i]=dp[0][i-1]+grid[0][i];
4. 遍歷順序：因為只能往下或是往右走，因此仰賴左邊跟上面的值去計算，因此從左到右，從上到下
最後回傳的就是到終點時的最小值dp[m-1][n-1]
*/