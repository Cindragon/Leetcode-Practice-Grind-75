class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        if(nums.size()==1)  return nums[0];
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=2;i<nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};

/*
一樣使用動態規劃的方式來解決
dp 數組定義：在索引值 i 的情況下，所能獲得的最大金幣總和為 dp[i]
遞推公式： dp[i]=max(dp[i-2]+nums[i], dp[i-1])，要搶這個房間跟不搶這個房間來去比較最大值
初始化：dp[0]=nums[0](只能偷這個房間)、dp[1]=max(nums[0], nums[1])(找兩個最大值)
遍歷順序：從2開始遍歷整個數組
最後回傳 dp[nums.size()-1](考慮到數組最後一個數之後所能獲得的最大金幣數)
*/