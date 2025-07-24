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
dp 數組定義：考慮到以 nums[i] 為結尾的最長遞增子序列長度為 dp[i]
遞推公式：dp[i]是為了要更新 dp[j]+1 的最大值
   對於每個 j < i，如果 nums[i] > nums[j]，
   則可以將 nums[i] 接在以 nums[j] 結尾的遞增子序列後面，
   此時 dp[i] 可以更新為 max(dp[i], dp[j] + 1)。
初始化：由於每個元素本身就可以視為長度為 1 的遞增子序列，因此 dp 數組皆初始化為 1
遍歷順序：兩層 for 迴圈進行比較， nums[i] > nums[j]，就直接更新dp[i]的值
若是 dp[i] 比 res 大，就將 res 值更新為 dp[i]
最後回傳 res
*/