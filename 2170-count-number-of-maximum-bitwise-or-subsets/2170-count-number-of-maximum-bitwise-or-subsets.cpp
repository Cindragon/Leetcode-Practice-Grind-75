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

/*
使用回溯算法的方式來解題，先找到最大的 OR 值
接著運用回溯算法遍歷整個陣列並且枚舉所有 OR 值
每個數字都有選跟不選兩條路
一旦目前的 OR 值等於最大值(找到組合)，res++
最後回傳 res
*/