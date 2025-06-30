class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used){
        res.push_back(path);
        if(startIndex>=nums.size()) return;
        for(int i=startIndex;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            backtracking(nums, i+1, used);
            used[i]=false;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
        return res;
    }
};