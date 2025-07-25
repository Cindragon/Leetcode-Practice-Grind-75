class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1=s.size(), len2=t.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[len1][len2]==len1;
    }
};

/*
也可以用動態規劃的方式來處理
dp 數組定義：以 i-1 為結尾的字串 s 與 j-1 為結尾的字串 t 的相同子序列長度為 dp[i][j]
遞推公式：
    若字元相同 dp[i][j]=dp[i-1][j-1]+!
    若不相同 dp[i][j]=dp[i][j-1](等於是我們不考慮這個字元)
初始化：一樣從 0 開始計算，dp 數組皆初始化為 0
遍歷順序：從 1 開始遍歷到字串結尾
最後若是 dp[i][j]=s.size()，說明 s 為 t 的子序列(return true)

*/


/*
雙指針寫法
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length(), m=t.length();
        int i=0,j=0;
        for(i=0;i<m && j<n;i++){
            if(s[j]==t[i]){
                j++;
            }
        }
        return (j==n);
    }
};
*/