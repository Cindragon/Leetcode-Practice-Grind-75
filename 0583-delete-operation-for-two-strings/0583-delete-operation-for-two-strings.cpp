class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for(int i=0;i<=word1.size();i++) dp[i][0]=i;
        for(int j=1;j<=word2.size();j++) dp[0][j]=j;
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j]+1, dp[i][j-1]+1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

/*
此題可以用動態規劃的方式來處理
dp 數組定義：在以 i-1 為結尾的 word1 字串以及 j-1 為結尾的 word2 字串中，
最少需要刪除 dp[i][j] 個字元成為相同的字串
遞推公式：
    字元相同：dp[i][j]=dp[i-1][j-1](不用考慮當前字元)
    字元不同：dp[i][j]=min(dp[i-1][j]+1, dp[i][j-1]+1)，看要從兩個字串中找到需要刪除的最小值
初始化：
    當 words2 為空字串時，word1 要跟 word2 一樣所需要刪除的字元數量為 i
    同理可用於 word1 為空字串時
遍歷順序：一樣從 1 開始遍歷到字串結尾
在最後回傳 dp[word1.size()][word2.size()]
*/