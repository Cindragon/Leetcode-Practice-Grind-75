class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0], prof=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<min) min=prices[i];
            if(prof<prices[i]-min){
                prof=prices[i]-min;
            }
        }
        return prof;
    }
};