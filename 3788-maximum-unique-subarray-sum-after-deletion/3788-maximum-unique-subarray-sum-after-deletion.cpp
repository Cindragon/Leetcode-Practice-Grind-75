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

/*
使用貪心算法的方式來做，先將數組進行排序
接著用迴圈的方式
若是相同元素不相加，其餘相加。而若是加了之後比原本的元素還要小，那就用原本的元素取代總和
最後回傳總和即可
*/