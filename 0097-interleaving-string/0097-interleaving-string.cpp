class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(), n=s2.size(), t=s3.size();
        if(m+n!=t)  return false;
        // 以 i-1 的字串 s1 跟 j-1 的字串 s2 能否組成 s3[0, i+j-1] 的字串
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0]=true;
        for(int i=1;i<=m;++i)   dp[i][0]=dp[i-1][0] && (s1[i-1]==s3[i-1]);
        for(int j=1;j<=n;++j)   dp[0][j]=dp[0][j-1] && (s2[j-1]==s3[j-1]);
        //s3[i+j-1] 要嘛來自 s1[i-1]，要嘛來自 s2[j-1]
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                dp[i][j]=(dp[i-1][j] && (s1[i-1]==s3[i+j-1])) || 
                (dp[i][j-1] && (s2[j-1]==s3[i+j-1]));
            }
        }
        return dp[m][n];
    }
};

/*
一樣用動態規劃的方式處理
1. dp 數組定義：以 i-1 的字串 s1 跟 j-1 的字串 s2 能否組成 s3[0, i+j-1] 的字串=dp[i][j]
2. 初始化：dp[0][0]=true(空字串與空字串可以組成空字串)
    dp[i][0]=dp[i-1][0] && (s1[i-1]==s3[i-1]) s1 的 i-1 個字元是否能組成 s3[0, i-1]
    dp[j][0]=dp[j-1][0] && (s2[j-1]==s3[j-1]) 同上
3. 遞推公式：
    dp[i][j]=(dp[i-1][j] && (s1[i-1]==s3[i+j-1]))  -> 取 s1 的字元
    || (dp[i][j-1] && (s2[j-1]==s3[i+j-1]));       -> 取 s2 的字元
    只要可以跟 s1[i-1] 或是 s2[j-1] 組成就可以為 true
4. 遍歷順序：
    從 i, j=開始遍歷，一直遍歷到兩個字串的結尾
最後回傳 dp[m][n]
*/