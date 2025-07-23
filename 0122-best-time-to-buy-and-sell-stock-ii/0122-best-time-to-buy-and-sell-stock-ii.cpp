class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        vector<vector<int>> dp(len, vector<int>(2, 0));
        dp[0][0]-=prices[0];
        dp[0][1]=0;
        for(int i=1;i<len;i++){
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1]=max(dp[i-1][1], dp[i-1][0]+prices[i]);
        }
        return dp[len-1][1];
    }
};
/*
這題用了貪心算法的思路為，找到獲利是正的時候再加總起來
利潤為負數就不用相加，最後回傳利潤加總。
    int maxProfit(vector<int>& prices) {
        int ans=0, prof=0;
        for(int i=prices.size()-1;i>0;i--){
            prof=prices[i]-prices[i-1];
            if(prof>0) ans+=prof;
        }
        return ans;
    }
*/

/*
同時也可以用動態規劃的方式解決
跟 買賣股票I 不一樣的是，本次股票可以多次買賣
因此 在持有股票的 dp[i][0]，其遞推公式要改為：
dp[i][0]=max(dp[i-1][0], dp[i-1][1]-prices[i])
如果在第 i 天持有股票，最大利潤應該要是不持有股票的第 i-1 天(dp[i-1][1])減去prices[i]才對
最後一樣回傳 dp[len-1][1]
*/