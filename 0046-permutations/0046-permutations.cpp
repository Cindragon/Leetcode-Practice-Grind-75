class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            used[i]=true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i]=false;
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool> used(n, false);
        backtracking(nums, used);
        return ans;
    }
};


/*
排列問題
排列與組合不同的地方在於：
    排列的元素順序是有差別的([1,2]跟[2,1]有差)，而組合的話則沒有差別([1,2]跟[2,1]沒差)
這題也是一樣用回溯算法來解
相較於組合問題，這題使用 used 數組來解決(看哪個元素有被用過)
傳入參數：nums 數組跟 used 數組
終止條件：path 的大小等於 nums 的大小，將 path 加入 ans 後return
單層遞迴邏輯：
    如果(used[i])，代表這個元素被用過了，直接continue
    然後將used[i]設為true
    path加入nums[i]
    接下來用backtracking跟回溯的方式還原
最後回傳 ans
*/