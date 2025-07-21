class Solution {
public:
    int numSquares(int n) {
        vector<unsigned long long> dp(n+1, INT_MAX);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i-j*j]+1, dp[i]);
            }
        }
        return dp[n];
    }
};
/*
一樣作為完全背包問題
dp 數組定義：最少需要 dp[i] 個完全平方數使其加總總和為 i，可重複使用數字
初始化：dp[0]=0，其他初始化為0，以免數值在遞推的過程中被蓋過
遞推公式：dp[i]=min(dp[i-j*j]+1, dp[i])，一樣找最小值，加或不加入這個完全平方數的個數有幾個
遍歷順序：先遍歷背包再遍歷物品，並且從1開始遍歷
最後回傳dp[n]
*/