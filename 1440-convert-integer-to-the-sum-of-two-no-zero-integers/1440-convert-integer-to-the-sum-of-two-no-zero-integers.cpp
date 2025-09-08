class Solution {
public:
    bool hasZero(int n){
        while(n>0){
            if(n%10==0) return true;
            else n=n/10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n/2;i++){
            int j=n-i;
            if(!hasZero(i) && !hasZero(j)){
                return {i, j};
            }
        }
        return {};
    }
};