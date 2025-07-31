class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else
                    dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][s.size()-1];
    }
};

/*
這題一樣可以用動態規劃的方式解決，跟 LeetCode 647 很像
dp 數組定義：在 [i, j] 區間的字串中最長的回文字串長度為 dp[i][j]
遞推公式：
    字元一樣：dp[i][j]=dp[i+1][j-1]+2(頭尾多兩個元素)
    字元不一樣：dp[i][j]=max(dp[i+1][j], dp[i][j-1])找到兩邊最長的回文子字串
初始化：當 i=j 的時候，只有一個元素，也等於是回文子字串
因此 dp[i][i] 要初始化為1，其他初始化為 0 即可
遍歷順序：由下往上，由左至右來遍歷
最後要回傳 dp[0][s.size()-1]，代表從 0 到字串結尾的最長回文子字串長度
*/