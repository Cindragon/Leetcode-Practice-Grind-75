class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==1) return 0;
        vector<vector<int>> dp(len, vector<int>(4, 0));
        dp[0][0]=-prices[0];
        for(int i=1;i<len;i++){
            dp[i][0]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][3])-prices[i]);
            dp[i][1]=max(dp[i-1][1], dp[i-1][3]);
            dp[i][2]=dp[i-1][0]+prices[i];
            dp[i][3]=dp[i-1][2];
        }
        return max({dp[len-1][1], dp[len-1][2], dp[len-1][3]});
    }
};

/*
這題採用動態規劃的方式來處理，由於還有冷凍期的關係，因此分為四種狀態
dp 數組定義：在 i 天時的狀態 j 所能獲得的最大金幣 dp[i][j]
遞推公式：分成四種狀態
    dp[i][0](買入股票)：最大值為前一天買入的狀態，以或是是在保持賣出股票跟冷凍期之後買入
    dp[i][1](保持賣出股票的狀態)：最大值為前一天的狀態，或是冷凍期的狀態
    dp[i][2](第 i 天賣出的狀態)：只能是在前一天買入之後賣出
    dp[i][3](冷凍期)：其實就跟保持賣出的狀態一樣
初始化：持有股票一定為 -prices[0]，其餘皆可初始化為 0
遍歷順序：每個狀態由前一天的狀態所決定，因此從小到大遍歷
最後回傳 三個狀態的最大值即可
*/
