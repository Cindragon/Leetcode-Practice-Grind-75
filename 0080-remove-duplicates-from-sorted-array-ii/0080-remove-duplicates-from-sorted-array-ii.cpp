class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())    return 0;
        int slow=0;
        int count=1;
        for(int fast=1;fast<nums.size();++fast){
            if(nums[slow]==nums[fast]){
                count++;
            }          
            else{   //遇到新數字
                count=1;
            }
            if(count<=2){   //小於兩個重複的值
                slow++;
                nums[slow]=nums[fast];
            }
        }
        return slow+1;
    }
};