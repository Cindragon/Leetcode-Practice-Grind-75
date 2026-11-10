class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=3 && k<=i;k++){
                dp[i]=min(dp[i], dp[i-k]+k*k+costs[i-1]);
            }
        }
        return dp[n];
    }
};

/*
dp 數組定義：從第 0 階到第 n 階的最小總成本 dp[i]
遞推公式：dp[i]=min(dp[i], dp[i-k]+k*k+costs[i-1])，要同步計算跳階 1~3 步的成本
初始化：dp[0]=0
遍歷順序：從1 開始遍歷，並且跳階要從1~3開始遍歷（不得超過原本的階層）
最後回傳 dp[n] 
*/

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna