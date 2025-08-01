class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1, 0);
        dp[0]=1;    // 第一個值始終是 1
        for(int i=1;i<=rowIndex;i++){
            for(int j=i;j>=1;j--){
                dp[j]+=dp[j-1];
            }
        }
        return dp;
    }
};

/*
這題一樣可以用 dp 的方式解決(空間為 O(K))
dp 數組定義：dp[j] 表示目前第 i 行（從第 0 行開始）中第 j 個元素的值
遞推公式：dp[j]+=dp[j-1]，從後面往前推，避免 dp[j-1] 被覆蓋掉
第 i 行第 j 個數字 = 上一行第 j 個數字 + 上一行第 j - 1 個數字
初始化：dp[0] 為 1，其他都初始化為 0
遍歷順序：i 是行數(從小到大)，j 是數字索引值(從大到小)
最後回傳 dp(更新完的數組)
*/