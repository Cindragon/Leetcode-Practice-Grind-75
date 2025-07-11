class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=cost.size();i++){
            dp[i]=min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[cost.size()];
    }
};

/*
建立一個dp數組，定義為：到達 i 位階時所需要的最小花費 dp[i]
遞推公式：找到最小花費是找 dp[i-1]+cost[i-1] 跟dp[i-2]+cost[i-2] 的最小值 
初始化：從第 0 階跟第 1 階開始都不需要花費，因此初始化為 0
遍歷順序就從2開始，遍歷到 cost.size()(到頂樓的層數)
最後回傳 dp[cost.size()]
*/