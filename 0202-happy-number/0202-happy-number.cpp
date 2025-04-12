class Solution {
public:
    int getsum(int n){
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> ans;
        int sum;
        while(1){
            sum=getsum(n);
            if(sum==1){
                return true;
            }
            if(ans.find(sum)!=ans.end()){
                return false;
            }
            else{
                ans.insert(sum);
            }
            n=sum;
        }
    }
};