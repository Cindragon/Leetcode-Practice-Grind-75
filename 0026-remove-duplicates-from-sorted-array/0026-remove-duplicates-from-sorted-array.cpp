class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slow=0;
        for(int fast=1;fast<nums.size();++fast){
            if(nums[fast]!=nums[slow]){ //找到新元素
                slow++;
                nums[slow]=nums[fast];  //放到 slow 的位置
            }
        }
        return slow+1;
    }
};