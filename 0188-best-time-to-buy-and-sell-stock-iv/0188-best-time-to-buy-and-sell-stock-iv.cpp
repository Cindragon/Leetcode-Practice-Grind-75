class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        if(len==0)  return 0;
        vector<vector<int>> dp(len, vector<int>(2*k+1, 0));
        for(int j=1;j<2*k;j+=2){
            dp[0][j]=-prices[0];    //j 為奇數時，其代表為持有該股票(偶數為賣出股票)
        }
        for(int i=1;i<len;i++){
            for(int j=0;j<2*k-1;j+=2){
                dp[i][j+1]=max(dp[i-1][j+1], dp[i-1][j]-prices[i]);
                dp[i][j+2]=max(dp[i-1][j+2], dp[i-1][j+1]+prices[i]);
            }
        }
        return dp[len-1][2*k];
    }
};

/*
這題一樣可以用動態規劃的方式處理，題目要求為最多買賣幾次，代表買賣的次數最多可以有 2*k 次(買賣各算一次)
dp 數組定義：第 i 天的狀態為 j，最大現金為 dp[i][j]。由於最多買賣k次，因此大小為 2*k+1
遞推公式：i從 1 開始，j 則從 0 開始+2，持續更新買進跟賣出的所獲得的最大現金
    dp[i][j+1]=max(dp[i-1][j+1], dp[i-1][j]-prices[i]);
    dp[i][j+2]=max(dp[i-1][j+2], dp[i-1][j+1]+prices[i]);
初始化：將奇數次買入的 dp[0][j] 都設為 -prices[0]，其餘為 0
遍歷順序：從小到大開始遍歷，持續更新最大值
最後回傳最後一次的未持有股票的 dp[len-1][2*k]
*/