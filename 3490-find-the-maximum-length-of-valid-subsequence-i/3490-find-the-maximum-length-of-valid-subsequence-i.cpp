class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0, odd=0, alternate=1, pre=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)    even++;
            else    odd++;
            
            if(i>=1&&nums[i]%2!=pre%2){
                alternate++;
                pre=nums[i];
            }
        }
        return max({even, odd, alternate});
    }
};