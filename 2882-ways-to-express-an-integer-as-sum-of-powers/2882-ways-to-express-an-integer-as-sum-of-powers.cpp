class Solution {
public:
    const int MOD=1e9+7;
    int intPow(int base, int exp) {
    int result = 1;
    for(int k = 0; k < exp; k++)
        result *= base;
    return result;
    }
    int solve(int n, int x, int i, vector<vector<int>>& dp){
        if(n==0)    return 1;
        int p=intPow(i, x);
        if(n<0||p>n)    return 0;
        if(dp[n][i]!=-1)    return dp[n][i];
        int ans=0;
        ans=(solve(n, x, i+1, dp)+solve(n-p, x, i+1, dp))%MOD;
        return dp[n][i]=ans;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n, x, 1, dp);
    }
};

/*
這題使用動態規劃的方式解決
dp 數組定義：dp[n][i] 表示：用從 i 開始的整數（i^x, (i+1)^x, ...）組合出 n 的方法數
遞推公式：選擇這個數跟不選擇這個數(使用遞迴)
dp[n][i] = dp[n][i+1] + dp[n - i^x][i+1]（不選 i + 選 i）
終止條件：
n == 0 時表示成功，回傳 1。
n < 0 或 i^x > n 時無解，回傳 0。
初始化：dp 數組皆初始化為 -1;
遍歷順序：從 1 開始最後到 i^x >n 或是 n<0
*/