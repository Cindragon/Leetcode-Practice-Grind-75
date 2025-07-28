class Solution {
public:
    int maxOr=0;
    int res=0;
    void backtracking(vector<int>& nums, int startIndex, int currentOr){
        if(startIndex==nums.size()){
            if(currentOr==maxOr){
                res++;
            }
            return;
        }
        // 選擇 nums[startIndex]
        backtracking(nums, startIndex+1, currentOr|nums[startIndex]);

        // 不選擇 nums[startIndex]
        backtracking(nums, startIndex+1, currentOr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        for(const auto&n:nums){
            maxOr|=n;
        }
        backtracking(nums, 0, 0);
        return res;
    }
};