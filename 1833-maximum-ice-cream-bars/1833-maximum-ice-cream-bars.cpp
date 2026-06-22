class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum=0;
        int count=0;
        for(const auto&c:costs){
            if(sum+c<=coins){
                sum+=c;
                count++;
            }
            else break;
        }
        return count;
    }
};