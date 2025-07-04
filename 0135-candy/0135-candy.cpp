class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        for(int i=1;i<ratings.size();i++){  //右邊比左邊大
            if(ratings[i]>ratings[i-1]){
                candy[i]=candy[i-1]+1;
            }
        }
        int ans=0;
        for(int i=ratings.size()-1;i>0;i--){    //左邊比右邊大
            if(ratings[i-1]>ratings[i]){
                candy[i-1]=max(candy[i - 1], candy[i] + 1);
            }
        }
        for(const auto&i:candy){
            ans+=i;
        }
        return ans;
    }
};

/*
一樣使用貪心算法
不要一次考慮兩種情況，一種想完載處理第二種
先定義一個數組，用1填滿(最少一個糖果)
接下來先考慮右邊比左邊大，糖果+1
接著考慮左邊比右邊大，此時要比較原本的 candy[i] 跟candy[i-1]+1誰大
最後加總所有糖果數量回傳
*/