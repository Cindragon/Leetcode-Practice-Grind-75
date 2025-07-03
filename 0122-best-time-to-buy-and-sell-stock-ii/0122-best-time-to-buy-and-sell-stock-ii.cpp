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