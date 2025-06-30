class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        sort(nums.begin(), nums.end());
        int left=0, maxLen=0;
        for(int right=0;right<nums.size();right++){
            while(nums[right]-nums[left]>1){
                left++;
            }
            if(nums[right]-nums[left]==1){
                maxLen=max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
};
/*
使用sort+雙指標的方式
將兩數進行比較，如果說右邊減左邊>1，left++(縮小左界)
如果相減等於1，那就來比較原本的maxLen或是right-left+1誰比較大
最後return maxLen
*/
