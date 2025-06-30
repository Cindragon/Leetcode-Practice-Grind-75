class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int startIndex){
        res.push_back(path);
        if(startIndex>=nums.size()) return;
        for(int i=startIndex;i<nums.size();i++){
            if(i>startIndex&&nums[i]==nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path.clear();
        res.clear();
        backtracking(nums, 0);
        return res;
    }
};