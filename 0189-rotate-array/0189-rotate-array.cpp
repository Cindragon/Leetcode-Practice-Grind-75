class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==0)    return;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};

/*
直接用 reverse 的函數來解決
k=k%n(取餘數避免重複反轉)
1.先將全部的陣列反轉一次
2.將開頭到nums[k-1]的地方進行反轉
3.將nums[k]到結尾的地方再次反轉
*/