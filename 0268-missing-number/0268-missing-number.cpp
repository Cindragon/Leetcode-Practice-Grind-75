class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int expSum=n*(n+1)/2;
        for(const auto&i:nums){
            expSum-=i;
        }
        return expSum;
    }
};