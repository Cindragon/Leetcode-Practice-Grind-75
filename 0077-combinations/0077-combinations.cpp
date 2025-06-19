class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int startindex){
        if(path.size()==k){
            res.push_back(path);
            return;
        }
        for(int i=startindex;i<=n-(k-path.size())+1;i++){
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};

/*
使用遞迴法來解決組合問題
先設立兩個類別成員變數res跟path來儲存結果
接下來確定參數以及回傳值
設計一個 void 型別的遞迴函式，額外傳入 startindex 表示目前遞迴到的起始數字
終止條件：如果path的大小等於k(代表符合題目要求)，就將path加入res裡面
單層遞迴邏輯：
    1. 使用 for 迴圈從 `startindex` 遍歷到 `n`(n其實可以做剪枝)
    2. 每次將目前數字 `i` 加入 path（做選擇）
    3. 遞迴下一層，`startindex` 設為 `i + 1`（確保數字不重複使用）
    4. 遞迴返回後，使用 `pop_back()` 撤銷剛才的選擇（回溯）
最後return res

剪枝方面的操作(在for迴圈中減少不必要的遍歷)：
i<=n-(k-path.size())+1
i是起始值，n是最後的值，k是所需要的個數，path.size()是當前陣列的大小
    // 如果還需要選 (k - path.size()) 個數，
    // 則目前最大可起始的 i 為：n - (k - path.size()) + 1
    // 否則就算選滿 i 到 n 的所有數字，也無法湊足 k 個，故可以提前結束。

舉例來說：
n = 4, k = 3，第一次遞迴時 path 為空（path.size() == 0）

我們最多只能從 i = 1 ~ 2 開始，因為：
    n - (k - path.size()) + 1 = 4 - (3 - 0) + 1 = 2

若 i 從 3 開始，就無法再湊出剩下的兩個數字（3, 4 不夠）
這樣就可以避免無效遞迴，加快速度。
*/