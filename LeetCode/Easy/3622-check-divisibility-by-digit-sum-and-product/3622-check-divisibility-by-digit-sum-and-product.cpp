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
        sum+=prod;
        cout<<sum;
        if(origin%sum==0)return true;
        else return false;
    }
};