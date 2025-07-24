class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        if(nums.size()==1)  return nums[0];
        dp[0]=nums[0];
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1]+nums[i], nums[i]);
            if(res<dp[i])   res=dp[i];
        }
        return res;
    }
};

/*
一樣可以用動態規劃的方式
dp 數組：在第 i 個數字時的最大子序列總和為 dp[i]
遞推公式：dp[i]=max(dp[i-1]+nums[i], nums[i]) 看要直接加總上去或是重新開始計算
初始化 dp[0]=nums[0]
遍歷順序：從 1 開始遍歷到底，並且用變數 res 儲存最大值
最後回傳 res
*/

/*
貪心算法
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

這題的貪心算法邏輯是：如果目前的連續和小於0，那乾脆就從下一個數開始重頭加總
因此在 for 迴圈中進行判斷，將sum進行加總
接著跟 res 做比較儲存最大值，最後回傳res
如果sum<0直接重新開始
*/