class Solution {
static bool cmp(int a, int b){
    return abs(a)>abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0&&k>0){
                nums[i]*=-1;
                k--;
            }
        }
        if(k%2==1) nums[nums.size()-1]*=-1;
        int sum=0;
        for(const auto&i:nums){
            sum+=i;
        }
        return sum;
    }
};

/*
使用 sort 加上自定義的比較函數來對數組進行絕對值的排列
接著開始對小於0的數字進行反轉
最後若是沒有用完反轉次數，就把數組最小的正數進行反轉
最後回傳總和
*/