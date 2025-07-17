class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(const auto&n:nums){
            sum+=n;
        }
        if(abs(target)>sum)     return 0;
        if((target+sum)%2==1)   return 0;
        int bagSize=0;
        bagSize=(target+sum)/2;
        vector<int> dp(bagSize+1, 0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=bagSize;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[bagSize];
    }
};

/*
首先要確認背包大小，將元素分為正與負兩堆，將所有元素進行加總
若是target的絕對值>sum(湊不出來) return 0
若是target+sum無法被2整除，一樣也湊不出來 return 0

dp數組的含義：在裝滿為 j 的背包，可以有dp[j]種方式
遞推公式：加總所有「使用 nums[i] 這個數字」可以組成總和 j 的方法數
想知道有幾種方式湊出「總和 j」，就可以把「總和 j - nums[i] 的方式數」加進來（因為現在又多了一個選 nums[i] 的機會）。
初始化：dp[0]=1，因為湊出容量為0的方式有一種，其餘直接初始化成 0 即可
接著一樣進行遍歷，先遍歷物品再遍歷背包(容量大到小)
最後回傳dp[bagSize]
*/