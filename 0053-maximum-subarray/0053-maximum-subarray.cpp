class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0];
        int res=sum;
        for(int i=1;i<nums.size();i++){
            if(sum<0) sum=0;
            sum+=nums[i];
            res=max(res, sum);
        }
        return res;
    }
};

/*
這局的貪心算法邏輯是：如果目前的連續和小於0，那乾脆就從下一個數開始重頭加總
因此在 for 迴圈中進行判斷，如果sum<0直接重新開始
接著跟 res 做比較儲存最大值，最後回傳res
*/