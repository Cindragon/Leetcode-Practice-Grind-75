class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int dp[2];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int sum=dp[0]+dp[1];
            dp[0]=dp[1];
            dp[1]=sum;
        }
        return dp[1];
    }
};

/*
除了遞迴也可以用動態規劃的方式來解決
先定義一個dp數組(只要記錄兩位)就好
遍歷公式為 F(n) = F(n - 1) + F(n - 2)
接著先初始化 dp[0]=0 跟dp[1]=1
之後開始進入迴圈，用sum記錄加總
最後回傳 dp[1]，即目前的 F(n)。
*/