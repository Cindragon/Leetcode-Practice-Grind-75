class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        int dp[2];
        dp[0]=1;
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
一樣用動態規劃的方式來解決
定義一個動態數組，dp[i] 代表爬到第 i 階的方法數(一樣只要兩個，因為每一個都等於前兩個相加)。
推導公式：dp[i]=dp[i-1]+dp[i-2]
初始化：
dp[0] = 1  // 站在地板上，不需要動作
dp[1] = 1  // 一階只有一種方式
接下來確定遍歷順序，從前到後遍歷
最後最後回傳 dp[1]，即為答案。
*/