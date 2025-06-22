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
            sum+=i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i+1);
            sum-=i;     //一樣作回溯
            path.pop_back();    //一樣作回溯
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 0, 1);
        return res;
    }
};

/*
跟前兩題一樣的情況
但是條件限制在1~9的數字
而且一個數字只能用一次
所以迴圈的條件要寫好
此外sum跟path都一樣要做回溯
*/