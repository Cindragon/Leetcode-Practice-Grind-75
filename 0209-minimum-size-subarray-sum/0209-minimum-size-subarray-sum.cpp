class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res=INT_MAX;
        int i=0, sum=0;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                res=min(res, j-i+1);
                sum-=nums[i];
                i++;
            }
        }
        return res==INT_MAX ? 0 : res;
    }
};

/*
用滑動窗口的方式來解題
從 nums [0] 開始計算加總
一旦等於或超過總和，便可以比較是否有更短的長度
最後用三元運算子來回傳res
*/