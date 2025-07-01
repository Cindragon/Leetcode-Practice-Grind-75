class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1] && !used[i - 1]) continue; //進行剪枝操作
            // used[i - 1] == true，說明同⼀樹枝used[i - 1]使⽤過
            // used[i - 1] == false，說明同⼀樹層used[i - 1]使⽤過
            // 要對同⼀樹層使⽤過的元素進⾏跳過
            if(used[i]) continue;   //path裡面已經有的元素直接跳過
            used[i]=true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};

/*
跟子集還有組合總和問題一樣，這題包含重複的元素
而重複的元素就需要先進行排序之後再來剪枝，才能避免挑到重複的元素
傳入參數：nums(排序後)跟used數組
終止條件：path的大小跟nums大小相等時加入res
單層遞迴邏輯：
    從i=0開始遍歷
    在 i>0 的情況下
        - 如果 nums[i] == nums[i-1]，說明這兩個元素值一樣。
        - 如果 used[i-1] == false，代表上一個相同元素在「同一層」中已經被跳過，為了避免重複，這個也應跳過。
    接著一樣used[i]==true的時候跳過(跳過選過的元素)
    used[i]設為true，path加入nums[i]
    接下來backtracking並且進行回溯
最後return res
*/