class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(vector<int>& nums, int startIndex){
        res.push_back(path);
        if(startIndex>=nums.size()){
            return;
        }
        for(int i=startIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        res.clear();
        backtracking(nums, 0);
        return res;
    }
};

/*
一樣用回溯算法來找到子集組合
設置類別成員 res 跟 path
傳入參數：nums數組跟startIndex(從哪個數開始加)
一開始要把path加入(不然一開始的空集合不會被加進去)
終止條件為startIndex>=nums.size() 結束遞迴 // 可以不用寫因為在for迴圈裡面已經寫好了
單層遞迴邏輯就是把遇到的數加入path，然後再用回溯的方式加入下個數再彈出
最後回傳res
*/