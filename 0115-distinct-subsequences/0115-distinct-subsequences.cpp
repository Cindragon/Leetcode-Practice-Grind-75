class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size()+1, vector<uint64_t>(t.size()+1));
        for(int i=0;i<=s.size();i++)    dp[i][0]=1;
        for(int j=1;j<=t.size();j++)    dp[0][j]=0;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};

/*
這題一樣可以用動態規劃的方式來解題
dp 數組定義：在以 i-1 為結尾的字串 s 跟以 j-1 為結尾的字串 t 組成相同字串的個數為 dp[i][j] 個
遞推公式：
    如果 s[i-1] == t[j-1]，則有兩種選擇：
    使用這個字元來配對：dp[i-1][j-1] or 不使用它：dp[i-1][j]
    因此：dp[i][j] = dp[i-1][j-1] + dp[i-1][j]

    字元不一樣的情況：dp[i][j]=dp[i-1][j](看上一個元素是否有匹配)
初始化：由於 dp 數組的含義為有幾個相同的字序列，因此初始化與最長共同子序列不同
當 t 為空字串時，它是任何字串的子序列，因此 dp[i][0] = 1
當 s 為空字串且 t 非空時，無法組成非空的 t，因此 dp[0][j] = 0
特別地，dp[0][0] = 1，表示空字串匹配空字串
遍歷順序：接下來從 1 開始遍歷到字串尾
最後回傳 dp[s.size()][t.size()]，即為總共的組合方式數
*/