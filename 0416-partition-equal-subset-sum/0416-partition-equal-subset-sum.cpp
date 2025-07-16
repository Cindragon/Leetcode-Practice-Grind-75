class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int target=0, sum=0;
        for(const auto&n:nums){
            sum+=n;
        }
        if(sum%2==1) return false;
        target=sum/2;
        vector<int> dp(target+1, 0);
        dp[target]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>0;j--){
                if(j-nums[i]>=0){
                    dp[j]=max(dp[j], dp[j-nums[i]]+nums[i]);
                }
            }
        }
        return dp[target]==target;
    }
};

/*
這題要用01背包的思維去解決，物品的重量等於其數值，也等於其價值
dp數組的定義：在容量為 j 的背包 (sum/2) 中，放進物品後，背的最⼤重量為 dp[j]
如果 dp[target]==target，說明可以裝滿其背包
因此先求出 target(加總/2)，如果sum為奇數則代表無法平分 return false
遞推公式：dp[j]=max(dp[j], dp[j-nums[i]]+nums[i])
背包內放入數值，其物品重量為 nums[i]，價值也是 nums[i]
進行初始化：由於題目只會給正整數，因此將 dp 數組初始化為 0
遍歷順序：一維 dp 數組中，先遍歷物品再遍歷背包，也要注意 j-nums[i]>=0 以避免越界
最後回傳 dp[target]==target
*/