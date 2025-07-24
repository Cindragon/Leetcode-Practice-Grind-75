class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(), len2=nums2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        int res=0;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    res=max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};

/*
以動態規劃的方式來解決本題
dp 數組的定義：在以 nums1[i-1] 為結尾以及 nums2[j-1] 為結尾的最長重複子序列長度為 dp[i][j]
遞推公式：if(nums1[i-1]==nums2[j-1])    dp[i][j]=dp[i-1][j-1]+1(因為要從前一個狀態+1)
初始化：將 dp 數組皆初始化為 0
遍歷順序：i 跟 j 從小到大進行遍歷，並且使用變數res記錄最大值
最後回傳res
*/