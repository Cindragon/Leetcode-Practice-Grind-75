class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        sort(nums.begin(), nums.end());
        int left=0, maxLen=0;
        for(int right=0;right<nums.size();right++){
            while(nums[right]-nums[left]>1){
                left++;
            }
            if(nums[right]-nums[left]==1){
                maxLen=max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
};
/*
使用sort+雙指標的方式，將兩數進行比較
   - 如果 nums[right] - nums[left] > 1，代表區間內數字差距太大，要縮小左界 → left++
   - 如果 nums[right] - nums[left] == 1，代表區間是合法的，計算長度 right - left + 1，更新 maxLen
最後return maxLen
*/