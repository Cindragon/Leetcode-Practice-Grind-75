class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int i, j, k, sum;
        for(i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1, right=nums.size()-1;
            while(left<right){
                sum=nums[i]+nums[left]+nums[right];
                int target=0;
                if(sum==target){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 去重 left，確保 left 不重複
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // 去重 right，確保 right 不重複
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }

                else if(sum>target){
                    right--;
                }
                else left++;
            }
        }
        return ans;
    }
};