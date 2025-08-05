class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int res=0;
        for(int i=0;i<fruits.size();i++){
            bool placed=false;
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=fruits[i]){
                    placed=true;
                    baskets[j]=-1;
                    break;
                }
            }
            if(placed==false){
                res++;
            }
        }
        return res;
    }
};