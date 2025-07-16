class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0, target;
        for(const auto&n:stones){
            sum+=n;
        }
        target=sum/2;
        vector<int> dp(target+1, 0);
        for(int i=0;i<stones.size();i++){
            for(int j=target;j>=stones[i];j--){
                dp[j]=max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        return sum-dp[target]-dp[target];
    }
};

/*
這題其實跟 LeetCode 416 一樣，需要盡量將兩堆石頭分成重量相近的兩堆，相減之後才會最小
dp 數組定義：容量為 j (總和/2)的背包，所能裝的最大重量(價值)為 dp[j]
遞推公式：dp[j]=max(dp[j], dp[j-stones[i]]+stones[i])，不放石頭跟放進石頭的最大值
初始化：dp數組為0，因為重量不會是負數，而且也就不會初始值給覆蓋
遍歷順序：先遍歷石頭，再遍歷背包(而且背包容量要大於石頭重量)
最後回傳時，將重量總和減去兩次dp[target](重量相近的兩堆相撞)
*/