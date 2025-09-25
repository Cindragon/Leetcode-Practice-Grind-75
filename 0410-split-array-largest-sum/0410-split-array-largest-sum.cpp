class Solution {
private:
    bool cansplit(vector<int>& nums, int k, long target){
        int sum=0;
        int count=1;
        for(const auto&n:nums){
            if(sum+n>target){
                sum=n;
                count++;
                if(count>k) return false;
            }
            else    sum+=n;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        long left=*max_element(nums.begin(), nums.end());
        long right=accumulate(nums.begin(), nums.end(), 0L);
        int ans=right;

        while(left<=right){
            long mid=left+(right-left)/2;
            if(cansplit(nums, k, mid)){
                ans=mid;
                right=mid-1;
            }
            else    left=mid+1;
        }
        return ans;
    }
};

/*
這題用到的是二方搜尋法加上 greedy

1. 先找到最大的元素 left 以及陣列的總和 right，我們在找最大子陣列和的時候需要先找到邊界，用左閉右閉的方式來找(型態為 long)，ans=right(一刀未切的情況下)

2. 在 left<=right 的時候，mid=left+(right-left)/2(也就是分成一半的情況下)
canSplit 檢查能否在分成 k 段的情況下，讓每段和 ≤ mid

3. 若需要的子陣列數量 > k，代表 mid 太小 → 要往右邊找。反之，代表可行或可以更小 → 往左邊縮。
4. canSplit 函式傳入 nums 陣列、k 段數量跟 target 值，用 sum 表示加總，用 count 表示幾段
    在遍歷 nums 陣列時進行加總(sum)
    若是加起來超過 target 了，那就劃一刀(count++)，重設 sum
    若 count > k → 需要的段數太多 → 回傳 false
    否則 sum+=n
遍歷結束後 count 仍 ≤ k，則回傳 true
*/