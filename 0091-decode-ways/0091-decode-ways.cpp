class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s.empty()||s[0]=='0')  return 0;
        vector<int> dp(n+1, 0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int oneNum=s[i-1]-'0';
            int twoNum=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(oneNum!=0){
                dp[i]+=dp[i-1];
            }
            if(10<=twoNum&&twoNum<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};

/*
用動規五部曲的方式來解決
1. dp 數組定義：在 [0, i-1] 的 s 字串中可以有 dp[i] 種的解碼方式
2. 遞推公式：因為會有兩種可能(一位數跟二位數)
    如果是個位數，那麼 dp[i]+=dp[i-1]，二位數則是 dp[i]+=dp[i-2]。
    要從前一位或前兩位的 dp[i] 做加總
3. 初始化：dp[0]=1(空字串的解碼方式只有一種：不解碼)，dp[1]=1(排除 s[0]=0 的情況了)，其餘初始化為 0
4. 遍歷順序：從 2 開始遍歷，一直遍歷到字串結尾，因為我們每次都要檢查「前一位」與「前兩位」
並且分為個位數跟二位數來看，並且轉變成數字去比較，最後回傳dp[n]
*/