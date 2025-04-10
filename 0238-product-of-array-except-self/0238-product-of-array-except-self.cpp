class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans, prefix, suffix;
        int product=1;
        for(int i=0;i<nums.size();i++){
            ans.push_back(product);
            product*=nums[i];
        }
        product=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]*=product;
            product*=nums[i];
        }
        return ans;
    }
};