class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int startIndex){
        if(path.size()>1){
            res.push_back(path);
        }
        unordered_set<int> uset;    //使用set幫本層元素去重
        for(int i=startIndex;i<nums.size();i++){
            if((!path.empty() && nums[i]<path.back())||uset.count(nums[i])){
                continue;
            }
            uset.insert(nums[i]);   //記錄已經用過這個元素了
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        res.clear();
        backtracking(nums, 0);
        return res;
    }
};


/*
跟子集問題2看似很相同，但是這次是不能將nums數組先排序來去重
而是要用hash table(set)來去重，將重複的元素標記起來
在同一層中就不會再次選到
傳入參數：nums數組跟startIndex
終止條件：在for迴圈中(如果path的元素數大於1就加入res)
在迴圈前要先設立一個set
單層遞迴邏輯：
    如果path不為零而且 nums[i] 小於path最右邊的樹(不是遞增) || uset中有nums[i]
    直接繼續迴圈
    若是通過就將現在的元素加入set
    接著繼續遞迴然後進行回溯
最後回傳res
*/