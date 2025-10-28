class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int startIndex){
        if(target==0){
            ans.push_back(path);
            return;
        }
        for(int i=startIndex;i<candidates.size();++i){
            if(i>startIndex && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target)    break;
            path.push_back(candidates[i]);
            backtracking(candidates, target-candidates[i], i+1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return ans;
    }
};
/*
跟 Leetcode 39 一樣的題型，只是現在數字不能重複使用
但是在迴圈中要再做剪枝
如果現在的數等於上一個數，那就continue
如果現在的數大於target，一樣代表找不到組合了，直接break
最後一樣回傳res
*/