class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)   return res;
            if(i>0 && nums[i]==nums[i-1])    continue;
            int left=i+1, right=nums.size()-1;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]>0)    right--;
                else if(nums[i]+nums[left]+nums[right]<0)   left++;
                else{
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(right>left && nums[left]==nums[left+1]) left++;
                    while(right>left && nums[right]==nums[right-1])   right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};

/*
一開始先進行排序，透過雙指針的方式來求解
接著先鎖定第一個數，並且要進行剪枝(因為不能重複)
接著開始設定雙指針的左右，在left<right的情況下
如果三個數相加>0 right--，如果<0 left++，如果相加為0就加入res
找到一組之後左右也需要剪枝(因為有可能有重複的數)
最後回傳res
*/
