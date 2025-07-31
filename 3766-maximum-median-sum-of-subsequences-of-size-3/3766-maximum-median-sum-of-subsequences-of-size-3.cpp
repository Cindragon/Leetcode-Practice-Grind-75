class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res=0;
        int n=nums.size()/3;
        for(int i = nums.size() - n * 2; i < nums.size(); i += 2){
            res+=nums[i];
        }
        return res;
    }
};