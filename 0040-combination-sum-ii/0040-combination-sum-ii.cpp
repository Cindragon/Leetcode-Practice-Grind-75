class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int target, int startindex){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i=startindex;i<nums.size();i++){
            if(i>startindex&&nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            path.push_back(nums[i]);
            backtracking(nums, target-nums[i], i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};

/*
跟 Leetcode 39 一樣的題型，只是現在數字不能重複使用
但是在迴圈中要再做剪枝
如果現在的數等於上一個數，那就continue
如果現在的數大於target，一樣代表找不到組合了，直接break
最後一樣回傳res
*/