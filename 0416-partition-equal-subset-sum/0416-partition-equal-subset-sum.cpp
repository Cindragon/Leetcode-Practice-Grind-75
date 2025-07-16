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