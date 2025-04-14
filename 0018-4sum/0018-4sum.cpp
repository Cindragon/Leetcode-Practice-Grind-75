class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int k=0;k<nums.size();k++){
            if(nums[k]>target && nums[k]>0 && target>0){
                break;
            }
            if(k>0 && nums[k]==nums[k-1]){
                continue;
            }
            for(int i=k+1;i<nums.size();i++){
                if(nums[k]+nums[i]>target && nums[k]+nums[i]>=0){
                    break;
                }
                if(i>k+1 && nums[i]==nums[i-1]){
                    continue;
                }
                int left=i+1, right=nums.size()-1;
                while(left<right){
                    if((long)nums[k]+nums[i]+nums[left]+nums[right]>target) right--;
                    else if((long)nums[k]+nums[i]+nums[left]+nums[right]<target) left++;
                    else{
                        ans.push_back({nums[k], nums[i], nums[left], nums[right]});
                        while(left<right&&nums[left]==nums[left+1]) left++;
                        while(left<right&&nums[right]==nums[right-1]) right--;
                        //找到解再做移動
                        left++; //
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

/*
使用跟 3sum 一樣的解法，只是在外層又多一個 for 迴圈確認變數 k 的位置
一樣先進行排序，以兩個迴圈來遍歷定位 nums[k] 跟 nums[i]
要注意的是，由於target有可能是負數，無法單純以「某一數字大於 target」就提前結束，條件剪枝要格外小心。
並且一樣要進行剪枝把其他重複的數值去除後再進到最後一個迴圈
最後一樣用雙指針遍歷，找到相加為 target (有可能會有long)的四組數字後 push_back 到 ans ，最後回傳 ans
*/