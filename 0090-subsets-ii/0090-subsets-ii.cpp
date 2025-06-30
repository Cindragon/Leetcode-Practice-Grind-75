class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int startIndex){
        res.push_back(path);
        if(startIndex>=nums.size()) return;
        for(int i=startIndex;i<nums.size();i++){
            if(i>startIndex&&nums[i]==nums[i-1]){   //對使用過的元素進行跳過(同層去重)
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

/*
由於子集內可以有重複的元素
因此需要去重，在加入子集之前先進行排序
然後就跟子集的問題一樣
使用回溯算法解決
傳入參數：nums數組跟startIndex
將path加入res中
單層遞迴邏輯：
    需要將重複的元素去除(注意這只會跳過「同一層」的重複值，下一層仍然會使用該數)
    接著一樣將nums[i]加入path
    進行遞迴之後，最後進行回溯
最後回傳res
*/