class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<double> dp(amount+1, 0);
        dp[0]=1;
        for(long long i=0;i<coins.size();i++){
            for(long long j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};

/*
這是一個完全背包的題目，因為每個硬幣都可以使用多次，要看作最多有幾種組合
dp 數組定義：達到總額為 j 的硬幣組合有 dp[j] 種
遞推公式：dp[j]+=dp[j-coins[i]](放了這個硬幣跟不放這個硬幣的組合加總)
初始化：dp[0]=1
遍歷順序：先遍歷物品再遍歷背包，而且背包大小採正序遍歷(小到大)
最後回傳dp[amount](用double或是 unsigned long long 都可以)
*/