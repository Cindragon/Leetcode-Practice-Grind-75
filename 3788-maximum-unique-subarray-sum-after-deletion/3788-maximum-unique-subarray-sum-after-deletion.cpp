class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])  continue;
            res+=nums[i];
            if(res<nums[i]) res=nums[i];    
        }
        return res;
    }
};