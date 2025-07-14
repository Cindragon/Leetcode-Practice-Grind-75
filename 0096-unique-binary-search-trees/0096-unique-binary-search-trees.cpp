class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};

/*
確立 dp 數組：dp[i]的定義為：i 個節點可以有多少種不同的 BST

遞推公式：從n=1,2,3可以推導出之間的相互關係，因為結構是很相似的

 dp[i] += dp[j-1] * dp[i-j]
    表示當「第 j 個節點」作為根節點時：
        - 左子樹有 j-1 個節點（對應 dp[j-1] 種組合）
        - 右子樹有 i-j 個節點（對應 dp[i-j] 種組合）
    所以這種情況的組合數為 dp[j-1] * dp[i-j]。
    把所有 j = 1 到 i 的可能都加總起來就是 dp[i]。

初始化：dp[0]=1(0個節點時有一種組合)

迴圈遍歷順序：由小到大遍歷，從i=1還有j=1開始遍歷

最後輸出dp[n]
*/