class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(), n=s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1;i<=m;++i)   dp[i][0]=dp[i-1][0]+int(s1[i-1]);
        for(int j=1;j<=n;++j)   dp[0][j]=dp[0][j-1]+int(s2[j-1]);
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j]+int(s1[i-1]), dp[i][j-1]+int(s2[j-1]));
                }
            }
        }
        return dp[m][n];
    }
};


/*
一樣用動態規劃的方式來去解決
dp 數組定義：以 i-1 為結尾的 s1 跟以 j-1 為結尾的 s2的最小 ASCII 刪除值為 dp[i][j]
初始化：dp[0][0] 為 0
    dp[i][0]=dp[i-1][0]+int(s1[i-1]) 在s2為空字串時，最小ASCII 刪除值為dp[i-1][0]+ 要刪除的 s1[i-1]
    dp[0][j]=dp[0][j-1]+int(s2[j-1]) 同理如上
遞推公式：
    s1[i-1]==s2[j-1]    dp[i][j]=dp[i-1][j-1](不用加總)
    s1[i-1]!=s2[j-1]    dp[i][j]=min(dp[i-1][j]+int(s1[i]), dp[i][j-1]+int(s2[j])(看刪去那一個字值最小)
遍歷順序：從i, j=1開始遍歷到字串結尾
最後回傳 dp[m][n]
*/
