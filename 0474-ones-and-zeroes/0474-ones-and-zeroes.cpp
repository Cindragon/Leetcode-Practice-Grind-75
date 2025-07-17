class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(const auto&str:strs){
            int x=0, y=0;   //計算 x 個 0 跟 y 個 1
            for(char c:str){
                if(c=='0')  x++;
                else    y++;
            }
            // 背包容量從大到小更新，避免重複使用當前字串
            for(int i=m;i>=x;i--){
                for(int j=n;j>=y;j--){
                    // 遞推公式：選 or 不選這個字串，取最大值
                    dp[i][j]=max(dp[i-x][j-y]+1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};

/*
本次要用到二維的 dp 數組來解題
dp 數組的定義：在最多使用 i 個 0 和 j 個 1 的限制下，最多可以選幾個字串（最大子集大小）
遞推公式：dp[i][j]=max(dp[i-x][j-y]+1, dp[i][j])
    如果不選當前字串：dp[i][j] 保持不變
    如果選了它：從 dp[i-x][j-y] 轉移過來，加上這個字串（+1）
初始化：dp[0][0]=0(最大子集長度為0)，其他也先設為0，以免在比較時覆蓋掉原本的值
遍歷順序：先遍歷物品再遍歷背包容量
物品先遍歷字串並且計算 0 跟 1 的個數，接下來由大到小遍歷背包
最後回傳 dp[m][n]
*/