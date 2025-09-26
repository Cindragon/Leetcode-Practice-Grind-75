class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0, n=nums.size();
        for(int k=n-1;k>=2;k--){
            int left=0, right=k-1;
            while(left<right){
                if(nums[left]+nums[right]>nums[k]){
                    ans+=(right-left);
                    --right;
                }
                else
                    ++left;
            }            
        }
        return ans;
    }
};

/*
運用 binary search 的方式來解這題
先將陣列進行排序，固定一邊最大邊，然後找到左右兩個邊界去比較兩邊相加是否大於第三邊
如果是的話那就代表這個區間之內的邊長都可以成為三角形
接著繼續縮小 right，若是無法組成三角形則擴大 left
*/