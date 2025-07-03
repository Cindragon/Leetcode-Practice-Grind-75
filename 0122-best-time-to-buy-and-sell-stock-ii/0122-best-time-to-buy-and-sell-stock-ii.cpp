class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, prof=0;
        for(int i=prices.size()-1;i>0;i--){
            prof=prices[i]-prices[i-1];
            if(prof>0) ans+=prof;
        }
        return ans;
    }
};
/*
這題用了貪心算法的思路為，找到獲利是正的時候再加總起來
利潤為負數就不用相加，最後回傳最大的利潤。
*/