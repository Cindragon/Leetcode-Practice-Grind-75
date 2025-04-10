class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result=INT32_MAX;
        int i=0, sum=0, subL;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                subL=(j-i+1);
                result=min(result, subL);
                sum=sum-nums[i];
                i++;
            }
        }
        return result==INT32_MAX ? 0:result;
    }
};