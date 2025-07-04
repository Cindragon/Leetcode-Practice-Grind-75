class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum=0;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()&&k>0;i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
                k--;
            }
        }
        sort(nums.begin(), nums.end());
        
        if(k%2==1){
            nums[0]=-nums[0];
        }

        for(const auto&i:nums){
            cout<<i<<" ";
            sum+=i;
        }
        return sum;
    }
};