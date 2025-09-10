class Solution {
public:
    int minInsertions(string s) {
        string rs=s;
        int n=s.size();
        reverse(rs.begin(), rs.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==rs[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};

/*
使用最長公共子字序列 (LCS) 的概念加上 DP 的概念來解題
首先要再多一個反轉後的字串，用來比較並計算字串的 LCS 回文長度
1. dp 數組的定義：在長度為 [0, i-1] 的 s 字串跟長度為 [0, j-1] 的 rs (反轉字串) 的 LCS 長度為 dp[i][j]
2. 遞推公式：
    在相等的情況下：dp[i][j]=dp[i-1][j-1]+1(再加上這個字元的長度)
    在字元不相等的情況下：dp[i][j] 就要從 dp[i-1][j] 跟 dp[i][j-1] 找最大值
3. 初始化：dp 數組皆設為 0，從 0 開始計算 LCS 的長度
4. 遍歷順序：兩個字串各自從 1 開始((因為 dp 數組定義為到 i-1 跟 j-1 的序列長度)
最後找到 LCS 的長度後，用原本的長度減去 LCS 便是我們最少需要操作插入的次數了
*/