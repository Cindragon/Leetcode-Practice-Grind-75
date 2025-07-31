class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res=0;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    if(j-i<=1||dp[i+1][j-1]){
                        dp[i][j]=true;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

/*
一樣使用動態規劃的方式來處理本題
dp 數組定義：在 [i, j] 的字串區間是否為回文字串(dp[i][j])
遞推公式(j>=i)：
    字元相同時有三種情況：i==j、i+1=j 以及 j-i>1
    在 j-i<=1 時 代表區間長度為 1 或 2（例如 "a" 或 "aa"），dp[i][j]=true，res++
    而在j-i>1時，要需判斷內部子區間 s[i+1...j-1] 是否為回文(dp[i+1][j-1])，
    如果是那 dp[i][j] 也一定是回文字串，res++
初始化：dp 數組要先全部初始化為 false，以便於計算
遍歷順序：
由於 dp[i][j] 依賴於 dp[i+1][j-1]，需要先計算較內層的子區間，
因此 i 要從後往前遍歷，j 則從 i 往後遍歷
最後回傳 res 即可(有幾個回文字串)
*/