class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==1)  return 0;
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        for(int i=1;i<len;i++){
            dp[i][0]=max(dp[i-1][0], -prices[i]);
            dp[i][1]=max(dp[i-1][1], dp[i][0]+prices[i]);
        }
        return dp[len-1][1];
    }
};

/*
這題除了貪心算法也可以用動態規劃的方式來處理
dp 數組定義：需要用二維數組來表示持有跟不持有這隻股票的最大金額
dp[i][0]：持有第 i 支 股票後所能獲得的最大金額 dp[i][0]
dp[i][1]：不持有第 i 支股票所能獲得的最大金額 dp[i][1]
遞推公式： 
    dp[i][0]=max(dp[i-1][0], -prices[i])，第 i-1 天就持有股票，或是第 i 天買進該股票
    dp[i][1]=max(dp[i-1][1], dp[i][0]+prices[i])，第 i-1 天不持有股票，或是在第 i 天進行買賣
初始化：dp[0][0] 買了第 0 支股票，dp[0][1] 不買這隻股票(0元)
遍歷順序：從1開始進行遍歷到數組盡頭
最後由於我不持有股票一定比持有股票的錢更多，所以只要回傳 dp[len-1][1] 就好
*/