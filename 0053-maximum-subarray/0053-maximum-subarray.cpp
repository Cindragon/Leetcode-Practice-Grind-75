class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>res) res=sum;
            if(sum<0) sum=0;
        }
        return res;
    }
};

/*
這局的貪心算法邏輯是：如果目前的連續和小於0，那乾脆就從下一個數開始重頭加總
因此在 for 迴圈中進行判斷，將sum進行加總
接著跟 res 做比較儲存最大值，最後回傳res
如果sum<0直接重新開始
*/