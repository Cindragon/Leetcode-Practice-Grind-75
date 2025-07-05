class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for(const auto&i:bills){
            if(i==5)    five++;
            if(i==10){
                if(five==0) return false;
                else{
                    ten++;
                    five--;;
                }
            }
            if(i==20){  //貪心策略(優先選擇以10+5的策略找零)
                if(ten>0&&five>0){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

/*
此題的貪心算法在於：在客人給20元的時候，優先以10+5來找零
因此要計算5跟10元鈔票的數量(20用不到不用統計)
針對每種情況來查看是否有足夠的零錢
*/