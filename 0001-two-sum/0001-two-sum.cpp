class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nums_map;
        for(int i=0;i<nums.size();i++){
            if(nums_map.find(target-nums[i])!=nums_map.end()){
                return{nums_map[target-nums[i]], i};
            }
            nums_map[nums[i]] = i;
        }
        return {};
    }
};

/*
使用 unordered_map 來儲存 nums[i] 對應的索引值（數值 ➜ 索引）
每次走訪 nums[i] 時，先計算 target - nums[i]
查看這個差值是否已經存在於 map 裡。
如果有找到就回傳兩者的索引值
若是沒有就加入到map中
*/