class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0, g=0, b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                r++;
            }
            else if(nums[i]==1){
                g++;
            }
            else
                b++;
        }
        for(int i=0;i<nums.size();i++){
            if(i<r) nums[i]=0;
            else if(i<r+g) nums[i]=1;
            else nums[i]=2;
        }
    }
};