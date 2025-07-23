class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==1)  return 0;
        vector<vector<int>> dp(len, vector<int>(5, 0));
        dp[0][0]=0;     //不操作
        dp[0][1]=-prices[0];    //第一次持有
        dp[0][2]=0;     //第一次不持有
        dp[0][3]=-prices[0];    //第二次持有
        dp[0][4]=0;     //第二次不持有
        for(int i=1;i<len;i++){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][1], dp[i-1][0]-prices[i]); 
            dp[i][2]=max(dp[i-1][2], dp[i-1][1]+prices[i]);
            dp[i][3]=max(dp[i-1][3], dp[i-1][2]-prices[i]);
            dp[i][4]=max(dp[i-1][4], dp[i-1][3]+prices[i]);
        }
        return dp[len-1][4];
    }
};

/*
同樣用動態規劃的方式解決
dp 數組定義：
分為五種狀態
不操作：dp[i][0]=0
第一次持有股票：第 i 天第一次持有股票 i 的最大金額為 dp[i][1]
第一次不持有股票：第 i 天第一次不持有股票 i 的最大金額為 dp[i][2](可能當天買當天賣出)
第二次持有股票：第 i 天第二次持有股票 i 的最大金額為 dp[i][1]
第二次不持有股票：第 i 天第二次不持有股票 i 的最大金額為 dp[i][2](也可能當天買當天賣出)
遞推公式：   
        dp[i][0]=0;
        dp[i][1]=max(dp[i-1][1], dp[i-1][0]-prices[i]); 
        dp[i][2]=max(dp[i-1][2], dp[i-1][1]+prices[i]);
        dp[i][3]=max(dp[i-1][3], dp[i-1][2]-prices[i]);
        dp[i][4]=max(dp[i-1][4], dp[i-1][3]+prices[i]);
初始化：dp[0][0]=0(不操作金額為零)、dp[0][1]=-prices[0](第一次買入第一支股票)
dp[0][2]=0(當天買當天賣出)、dp[0][3]=-prices[0](第二次當天買入)、dp[0][4]=0(同樣當天買賣)
遍歷順序：從 1 開始遍歷至數組結尾
最後回傳 dp[len-1][4] 
*/