class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<double> dp(target+1, 0);
        dp[0]=1;
        for(int i=0;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};

/*
跟 Coin change II 很像，但是這一題要求的是有多少種排列
因此要先遍歷背包再遍歷物品
dp 數組：總和為 i 的情況下有 dp[i] 種的排列方式可以湊出來
遞推公式：一樣 dp[i]+=dp[i-nums[j]]
初始化：dp[0]為1，其他皆初始化為0
遍歷順序：先遍歷背包再遍歷物品，每一次重新遍歷背包容量時都會從物品一開始裝進背包
需要檢查是否為超過限制
最後回傳 dp[target]
*/