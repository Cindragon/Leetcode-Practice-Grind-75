class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        for(int i=0;i<=n;++i){
            dp[i]=dp[i>>1]+(i&1);
        }
        return dp;
    }
};
/*
用 dp 回收前面計算過的位元
i >> 1：把 i 右移一位，也就是把「最後一個 bit」丟掉。
→ 意思是「移除最低位元後的那個數」的 1 的個數。

(i & 1)：檢查最低位元是不是 1。
→ 如果最低位是 1，就加 1；否則加 0。
*/