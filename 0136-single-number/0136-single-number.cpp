class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(const auto&n:nums){
            ans^=n;
        }
        return ans;
    }
};

/*
使用 Bitwise XOR 的邏輯(相同數進行XOR之後會抵消)
- 相同的數進行 XOR（^）會抵消為 0：a ^ a = 0
- 任意數與 0 XOR 不變：a ^ 0 = a
最後回傳 ans(唯一的一個數字)
*/