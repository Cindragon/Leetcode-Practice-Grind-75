class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len=nums.size();
        if(len==1)  return 1;
        vector<int> dp(len, 1);
        int res=1;
        for(int i=1;i<len;i++){
            if(nums[i]>nums[i-1]){
                dp[i]=dp[i-1]+1;
            }
            if(res<dp[i])   res=dp[i];
            cout<<dp[i];
        }
        return res;
    }
};