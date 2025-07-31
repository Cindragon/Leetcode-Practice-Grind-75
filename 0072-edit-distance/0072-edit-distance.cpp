class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1));
        for(int i=0;i<=word1.size();i++)    dp[i][0]=i;
        for(int j=1;j<=word2.size();j++)    dp[0][j]=j;
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1});
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

/*
一樣可以用動態規劃的方式來解決
dp 數組定義:以 i-1 為結尾的 word1 跟以 j-1 為結尾的 word2，
最少需要 dp[i][j] 次的操作才可讓兩個字串相等(刪除、增加或是替換)
遞推公式：
    字元相同：不需要操作    dp[i][j]=dp[i-1][j-1]
    字元不相同：可以從三個方向找最小值，刪除(增加) word1、刪除(增加) word2 或是從上一個字串中進行替換
初始化：
當 word2 為空字串時，要讓 word1 等於 word2 的操作次數為 i(刪去 i 個字元)
同理可用於 word1 為空字串時
遍歷順序：從 1 開始遍歷到兩個字串的結尾
最後回傳 dp[word1.size()][word2.size()]
*/