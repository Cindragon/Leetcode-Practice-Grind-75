class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, prod=1;
        int origin=n;
        while(n!=0){
            int num=n%10;
            sum+=num;
            prod*=num;
            n=n/10;
        }
    return (n%(sum+prod)==0);
    }
};