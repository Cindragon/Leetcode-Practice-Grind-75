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
        }
        return res;
    }
};

/*
這題可以用貪心算法也可以用動態規劃的方式處理
遞推公式中，只要 nums[i]>nums[i-1]，dp[i]=dp[i-1]+1(長度又變長了)
接著只要記錄最大值並且回傳即可
*/