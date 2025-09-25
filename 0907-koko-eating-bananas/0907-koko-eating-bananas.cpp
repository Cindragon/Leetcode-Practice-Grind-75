class Solution {
private:
    bool canEat(const vector<int>& piles, int mid, int h){
        int hour=0;
        for(const auto&p:piles){
            hour+=(p+mid-1)/mid;// 向上取整公式：ceil(p / k) = (p + k - 1) / k
            if(hour>h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(), piles.end());

        while(left<=right){
            int mid=left+(right-left)/2;
            if(canEat(piles, mid, h)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left; //最小可行速度
    }
};

/*
跟 Leetcode 410 、 1011 是同一個模板
用二元搜尋法的方式來解決
左右邊界：
    左邊：1(至少吃一根)
    右邊：最大元素(一次最多吃一堆)
接著找到 mid 為何，並且透過 canEat 函式來看是不是能在 h 小時內吃完
如果可以，就再看看能不能一小時吃更少的香蕉
要注意小時需要向上取整數，其計算公式為：
    ceil(a/b)=(a+b-1)/b
*/