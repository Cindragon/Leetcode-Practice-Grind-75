class Solution {
private:
    bool canShip(vector<int>& weights, int days, int target){
        int sum=0;
        int dayCount=1;
        for(const auto&w:weights){
            if(sum+w>target){
                sum=w;
                dayCount++;
                if(dayCount>days)   return false;
            }
            else    sum+=w;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight=*max_element(weights.begin(), weights.end());
        int sumWeight=accumulate(weights.begin(), weights.end(), 0);
        int ans=sumWeight;
        while(maxWeight<=sumWeight){
            int mid=maxWeight+(sumWeight-maxWeight)/2;
            if(canShip(weights, days, mid)){
                ans=mid;
                sumWeight=mid-1;
            }
            else{
                maxWeight=mid+1;
            }
        }
        return ans;
    }
};

/*
跟 Leetcode 410 是同一個模板
用二元搜尋法的方式來解決
*/