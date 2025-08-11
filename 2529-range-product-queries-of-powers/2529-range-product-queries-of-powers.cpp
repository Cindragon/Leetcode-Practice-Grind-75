class Solution {
public:
    const int MOD = 1000000007;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int power = 1;
        while (n > 0) {
            if (n & 1) {
                powers.push_back(power);
            }
            power <<= 1;
            n >>= 1;
        }
        vector<int> result;
        for(int i = 0; i<queries.size(); i++){
            int p = 1;
            for(int j = queries[i][0]; j<=queries[i][1]; j++){
                p = ((long long)p*powers[j])%MOD;
            }
            result.push_back(p);
        }
        return result;
    }
};

/*
先用 power 陣列將 n 拆成 2 的冪
接著逐個計算 queries 的區間乘積，並且進行取模(以免數字太大)
最後把結果加入到result中
*/