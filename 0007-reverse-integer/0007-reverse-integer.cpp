class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x!=0){
            int digit=x%10;
            if(ans>INT_MAX/10||ans<INT_MIN/10){
                return 0;
            }
            ans=ans*10+digit;
            x/=10;
        }
        return ans;
    }
};

/*
在計算的時候要注意溢位問題
如果比最大值大或最小值還要小，那就直接 return 0
在C++也可以直接對負數去做運算
*/