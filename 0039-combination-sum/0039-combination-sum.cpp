class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& candidates, int target, int startindex){
        if(target==0){
            res.push_back(path);
            return;
        }
        for(int i=startindex;i<candidates.size();i++){
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);
            backtracking(candidates, target-candidates[i], i);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};

/*
一樣使用backtracking的方式來找出所有組合
題目有提到可以使用相同的數字
先將陣列進行排序
遞迴的邏輯如下
設置void型態的遞迴函數，將陣列、target以及索引值傳入函數
終止條件：
    target==0的時候，將path傳入res
單層遞迴邏輯：
    1. 剪枝：如果當前的數值大於target(代表找不到結果了)，直接離開迴圈
    2. 2. 每次將目前數字 `i` 加入 path（做選擇）
    3. 遞迴下一層，`startindex` 設為 `i `（因為數字可以重複使用）
    4. 遞迴返回後，使用 `pop_back()` 撤銷剛才的選擇（回溯）
最後回傳res
*/