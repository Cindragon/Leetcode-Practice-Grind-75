class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len==1) return len;
        int res=1;
        vector<int> dp(len, 1);
        dp[0]=1;
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
            if(res<dp[i]){
                res=dp[i];
            }
        }
        return res;
    }
};

/*
這題可以使用動態規劃的方式處理
dp 數組定義：考慮到以 nums[i] 為結尾的最大遞增子序列長度為 dp[i]
遞推公式：dp[i]是為了要更新 dp[j]+1 的最大值
初始化：由於每個子序列的最小單位為1，因此 dp 數組皆初始化為 1
遍歷順序：兩層 for 迴圈進行比較，一旦前面的數比較大，就直接更新dp[i]的值
若是 dp[i] 比 res 大，就將 res 值更新為 dp[i]
最後回傳 res
*/