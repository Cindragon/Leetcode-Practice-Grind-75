class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currSum=0;
        int totalSum=0;
        int start=0;
        for(int i=0;i<gas.size();i++){
            currSum+=(gas[i]-cost[i]);
            totalSum+=(gas[i]-cost[i]);
            if(currSum<0){
                start=i+1;
                currSum=0;
            }
        }
        if(totalSum<0) start=-1;
        return start;
    }
};

/*
使用貪心算法的方式來算
定義一個currSum來找到從哪裡開始比較好，totalSum 用來計算如果消耗始終大於補充，代表找不到起始位置
在for迴圈中，currSum跟totalSum持續相加油量差
如果currSum<0，說明這個位置沒有辦法當起始位置
只能在從i+1再繼續開始
最後回傳start
*/