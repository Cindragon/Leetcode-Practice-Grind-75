class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unsigned long long> dp(amount+1, INT_MAX);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                if(j-coins[i]>=0){
                    dp[j]=min(dp[j-coins[i]]+1, dp[j]);
                }
            }
        }
        if (dp[amount]==INT_MAX) return -1;
        else return dp[amount];
    }
};

/*
這題一樣是完全背包題目
dp 數組定義：湊滿總額為 j 的最少需要 dp[j] 個硬幣
初始化：dp[0]=0(題目描述)，其餘初始化為最大值(避免在遞推的過程中將值覆蓋掉)
遞推公式：dp[j]=min(dp[j-coins[i]]+1, dp[j])，放跟不放這個硬幣的差別找最小值
遍歷順序：先遍歷物品再遍歷背包
最後判斷若是沒辦法找到解就回傳 -1
*/