class Solution {
public:
    int robHouse(vector<int>& nums, int start, int end){
        if(end==start)  return nums[end];
        vector<int> dp(nums.size());
        dp[start]=nums[start];
        dp[start+1]=max(nums[start], nums[start+1]);
        for(int i=start+2;i<=end;i++){
            dp[i]=max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        if(nums.size()==1)  return nums[0];
        int result1=robHouse(nums, 0, nums.size()-2);
        int result2=robHouse(nums, 1, nums.size()-1);
        return max(result1, result2);
    }
};

/*
這題也是動態規劃，跟House Robber I 不一樣的是要考慮頭尾相連
因此分成兩個部分來去求值：考慮第一個元素、不考慮最後一個元素 & 考慮最後一個元素，不考慮第一個元素
透過 House Robber I 的邏輯(函數)來各自求值，最後兩個求最大值
dp 數組定義：在考慮索引值為 i 的元素時，所能獲得的最大金幣為 dp[i]
遞推公式：dp[i]=max(dp[i-2]+nums[i], dp[i-1])
初始化：從 start 跟 start 的下一個去推算
遍歷順序：從 start+2 一直到 end
最後回傳 dp[end] 進行比較
*/