class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1=text1.size(), len2=text2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        int res=0;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};

/*
這題可以使用動態規劃的思路去解決
dp 數組定義：在長度為 [0, i-1] 的 text1 與長度為 [0, j-1] 的 text2 中的最長公共子序列長度為 dp[i][j]
遞推公式：dp[i][j]可以有兩個狀態：text1[i-1]==text2[j-1]以及字元不相等
    在相等的情況下：dp[i][j]=dp[i-1][j-1]+1(再加上這個字元的長度)
    在字元不相等的情況下：dp[i][j] 就要從 dp[i-1][j] 跟 dp[i][j-1] 找最大值
初始化：一樣將 dp 數組初始化為 0(從0開始往上加)
遍歷順序：各自從 1 開始(因為dp數組定義為到 i-1 跟 j-1的序列長度)
最後回傳 dp[len1][len2]
*/