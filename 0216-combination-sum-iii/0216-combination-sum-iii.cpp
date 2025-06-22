class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int targetSum, int k, int sum, int startIndex){
        if(path.size()==k){
            if(sum==targetSum){
                res.push_back(path);
                return;
            }
        }
        for(int i=startIndex;i<=9;i++){
            if(sum+i>targetSum) break;
            path.push_back(i);
            backtracking(targetSum, k, sum+i, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 0, 1);
        return res;
    }
};