class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        int dp[3];  //vector<int> dp(n + 1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            int sum=dp[1]+dp[2];
            dp[1]=dp[2];
            dp[2]=sum;
        }
        return dp[2];
    }
};

/*
一樣用動態規劃的方式來解決
定義一個動態數組，dp[i] 爬到第 i 層樓梯，有 dp[i] 種⽅法(一樣只要兩個，因為每一個都等於前兩個相加)。
推導公式：dp[i]=dp[i-1]+dp[i-2]
初始化：
dp[1] = 1  // 一階有一種方法
dp[1] = 1  // 二階有兩種方式
dp[0]是沒有意義的(因為在題目中有提到n是正整數)
接下來確定遍歷順序，從前到後遍歷
最後最後回傳 dp[2]，即為答案。
*/