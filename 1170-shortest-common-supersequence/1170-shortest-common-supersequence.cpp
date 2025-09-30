class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size(), n=str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans;
        int i=m, j=n;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                --i;
                --j;
            }
            else if(dp[i-1][j]>=dp[i][j-1]){
                ans.push_back(str1[i-1]);
                --i;
            }
            else{
                ans.push_back(str2[j-1]);
                --j;
            }
        }
        while(i>0)  ans.push_back(str1[--i]);
        while(j>0)  ans.push_back(str2[--j]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
可以結合 1143 題的解法來去想
先找到兩個字串 LCS 的長度，接下來開始從後面遍歷到前面
2. 從字串尾端開始回溯 dp 表，建構最短共同超序列 (SCS)：
   - 當 i > 0 且 j > 0 時：
     1) 若 str1[i-1] == str2[j-1]：
        → 字母相同，是 LCS 的一部分，只加入一次 ans，然後同時向左上移動 (i--, j--)。
     2) 若字母不同：
        → 若 dp[i-1][j] >= dp[i][j-1]：選 str1[i-1]，往上移動 (i--)。
        → 否則：選 str2[j-1]，往左移動 (j--)。
        
3. 如果 i>0 或 j>0 代表我們還有沒有加入ans的字母，則需要進行處理
4. 最後因為是從後面往前加，所以字串要進行反轉。   
*/